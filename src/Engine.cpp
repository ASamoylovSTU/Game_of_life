#include "Engine.h"
#include <algorithm>

Engine::Engine(const ushort _width, const ushort _height)
    : width(_width)
    , height(_height)
    , visualizer(_width, _height)
{   
    matrix = std::make_shared<std::vector<uchar> >(width * height, 0);
    nextgen = std::make_shared<std::vector<uchar> >(width * height, 0);
}

void Engine::set_cell_state(const ushort x, const ushort y, const bool state)
{
    if (x > width)
    {
        throw std::runtime_error("X coordinate is more than matrix width");
    }
    if (y > height)
    {
        throw std::runtime_error("Y coordinate is more than matrix height");
    }
    if (state)
    {
        // activate cell
        (*nextgen)[x + (y * width)] |= 1;
    }
    else
    {
        // deactivate cell
        (*nextgen)[x + (y * width)] &= ~0x01;
    }
    // notify all neigbours about state change
    notify_neighbours(x, y, state);
    // display cell on the field
    visualizer.set_cell(x, y, state);
}

void Engine::next_generation(const size_t generation)
{
    if (generation == 0)
    {
        throw std::runtime_error("Number of generation should be more than 0");
    }
    for (size_t gen = 0; gen < generation; gen++)
    {
        // copy displayed matrix
        (*matrix) = (*nextgen);
        
        for (ushort i = 0; i < width; i++)
        {
            for (ushort j = 0; j < height; j++)
            {
                if ((*matrix)[i + (j * width)] == 0)
                {
                    // cell would not be changed
                    continue;
                }

                // get state from first bit
                bool state = (*matrix)[i + (j * width)] & 1;
                // get neigbours from 2-5 bits
                char neigbours = (*matrix)[i + (j * width)] >> 1;

                if (state)
                {
                    if (neigbours < 2 || neigbours > 3)
                    {
                        // deactivate live cell
                        set_cell_state(i, j, false);
                    }
                }
                else
                {
                    if (neigbours == 3)
                    {
                        // activate dead cell
                        set_cell_state(i, j, true);
                    }
                }
            }
        }
    }
}

void Engine::display(int timeout)
{
    // if timeout is 0 the picture will be freezed until any button will be pressed
    // if timeout if more than 0 the picture will be freezed for n ms
    visualizer.display(timeout);
}

shared_vector Engine::get_matrix() const
{
    return nextgen;
}
void Engine::notify_neighbours(const ushort x, const ushort y, bool state)
{
    // variables define position of neigbours
    // additional logic is needed for edge cells
    int xleft, xright, ytop, ybottom;
    // pointer to current cell
    auto cell_ptr = (*nextgen).data() + (y * width) + x;

    if (x == 0)
    {
        xleft = width - 1; // left edge
    }
    else
    {
        xleft = -1; // no edge
    }
    if (y == 0)
    {
        ytop = (height - 1) * width; // top edge
    }
    else
    {
        ytop = -width; // no edge
    }
    if (x == (width - 1))
    {
        xright = -(width - 1); // right edge
    }
    else
    {
        xright = 1; // no edge
    }
    if (y == (height - 1))
    {
        ybottom = -(height - 1) * width; // bottom edge
    }
    else
    {
        ybottom = width; // no edge
    }

    // change neigbours count starting from second bit
    int modifier = 0x2;

    // if cell became dead neighbours cell should be decremented
    if (!state) modifier *= -1;

    cell_ptr[ytop + xleft] += modifier; // upper left
    cell_ptr[ytop] += modifier; // upper
    cell_ptr[ytop + xright] += modifier; // upper right
    cell_ptr[xleft] += modifier; // left
    cell_ptr[xright] += modifier; // right
    cell_ptr[ybottom + xleft] += modifier; // bottom left
    cell_ptr[ybottom] += modifier; // bottom
    cell_ptr[ybottom + xright] += modifier; // bottom right
}
