#include "Filter.h"


Filter::Filter(int up, int left, int bottom, int right) {
    _up = up;
    _left = left;
    _bottom = bottom;
    _right = right;
}

int Filter::up(image_data& image) {
    return _up == 0 ? 0 : image.h / _up;
}

int Filter::left(image_data& image) {
    return _left == 0 ? 0 : image.w / _left;
}

int Filter::bottom(image_data& image) {
    return _bottom == 0 ? 0 : image.h / _bottom;
}

int Filter::right(image_data& image) {
    return _right == 0 ? 0 : image.w / _right;
}
