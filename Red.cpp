#include "Red.h"

Red::Red(int up, int left, int bottom, int right):Filter(up, left, bottom, right) {};

bool Red::run(image_data& image) {
    if (!image.pixels) {
        return false;
    }
    int& c = image.compPerPixel;
    for (int i = up(image); i < bottom(image); i++) {
        for (int j = left(image); j < right(image); j++) {
            image.pixels[(i * image.w + j) * c] = 255;
            image.pixels[(i * image.w + j) * c + 1] = 0;
            image.pixels[(i * image.w + j) * c + 2] = 0;
        }
    }
    return true;
};

