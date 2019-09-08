#pragma once

#include "Visualizer.h"

// Class implements Game-of-life logic
class Engine
{
public:
    Engine(const ushort _width, const ushort _height);
    ~Engine();

    // change the state of the single cell
    void set_cell_state(const ushort x, const ushort y, const bool state = true);

    // run engine for n generations
    void next_generation(const size_t generation = 1);

    // display matrix
    void display(int timeout = 1);

    // get current matrix
    uchar* get_matrix() const;


private:
    // methods
    // notify all neighbors cells about state changes
    void notify_neighbours(const ushort x, const ushort y, bool state);

    // variables
    const ushort width;
    const ushort height;
    // matrix with current cells
    // each cell use 5 bits
    // first bit is state of cell (live or dead)
    // 2-5 bits represent alive neighbours count
    // 6-8 bits unused
    uchar* matrix;
    // matrix with cells states on the next generation
    uchar* nextgen;
    Visualizer visualizer;
};
