#include "Red.h"

Red::Red(int up, int left, int bottom, int right):Filter(up, left, bottom, right) {};

bool Red::run(image_data& image) {
    if (!image.pixels) {
        return false;
    }
    int& c = image.compPerPixel;
    for (int i = left(image); i <= right(image); i++) {
        for (int j = up(image); j >= bottom(image); j--) {
            image.pixels[(i * image.w + j) * c] = 255;
        }
    }
    return true;
};

