#include "Visualizer.h"

Visualizer::Visualizer(const ushort _width, const ushort _height)
    : width(_width * SCALE)
    , height(_height * SCALE)
{
    // create field to display cells
    field = cv::Mat(_height * SCALE, _width * SCALE, CV_8UC3, BLACK);

    // create white lines for better picture
    // vertical
    for(ushort i = SCALE; i < _width * SCALE; i += SCALE)
	{
        cv::line(field, cv::Point(i, 0), cv::Point(i, _height * SCALE), WHITE);
	}
    // horizontal
    for(ushort i = SCALE; i < _height * SCALE; i += SCALE)
	{
        cv::line(field, cv::Point(0, i), cv::Point(_width * SCALE, i), WHITE);
	}

}

void Visualizer::set_cell(const ushort x, const ushort y, const bool state)
{
    // check if cell is dead or live
    cv::Scalar color = state? WHITE: BLACK;

    // calc the square to fill
    cv::Point start((x * SCALE) + 1, (y* SCALE) + 1);
    cv::Point end(((x + 1) * SCALE) - 1, ((y + 1) * SCALE) - 1);

    // fill the square
    cv::rectangle(field, start, end, color, -1);
}

void Visualizer::display(int timeout) const
{
    // create window
    cv::namedWindow(WINDOW_NAME);

    // display matrix on window
    cv::imshow(WINDOW_NAME, field);

    //wait for button press if needed
    cv::waitKey(timeout);
}
