#pragma once

#include <opencv2/opencv.hpp>

#define SCALE 5 // size of one cell in the window
#define WHITE cv::Scalar(255, 255, 255) // color of live cells
#define BLACK cv::Scalar(0, 0, 0) // color of dead cells
#define WINDOW_NAME "window" // name of the window to display

class Visualizer
{
public:
    Visualizer(const ushort _width, const ushort _height);

    // display cell on the field
    void set_cell(const ushort x, const ushort y, const bool state);

    // display whole field
    // if timeout is 0 the picture will be freezed until any button will be pressed
    // if timeout if more than 0 the picture will be freezed for n ms
    void display(int timeout = 1) const;

private:
    // displayed matrix
	cv::Mat field;
    const int width;
    const int height;
};
