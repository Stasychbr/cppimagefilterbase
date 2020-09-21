#pragma once
#include "png_toolkit.h"

class Filter {
private:
    int _up;
    int _left;
    int _bottom;
    int _right;
protected:
    Filter(int up, int left, int bottom, int right);
public:
    virtual bool run(image_data& image) = 0;
    int up(image_data& image);
    int left(image_data& image);
    int bottom(image_data& image);
    int right(image_data& image);
    virtual ~Filter() {};
};
