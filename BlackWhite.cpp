#include "BlackWhite.h"

BlackWhite::BlackWhite(int up, int left, int bottom, int right) :Filter(up, left, bottom, right) {}


unsigned char BlackWhite::intensity(image_data& image, int row, int col) {
    if (!image.pixels) {
        return 0;
    }
    int& c = image.compPerPixel;
    unsigned char& r = image.pixels[(row * image.w + col) * c];
    unsigned char& g = image.pixels[(row * image.w + col) * c + 1];
    unsigned char& b = image.pixels[(row * image.w + col) * c + 2];
    return 0.3 * r + 0.6 * g + 0.1 * b;
}

bool BlackWhite::run(image_data& image) {
    if (!image.pixels) {
        return false;
    }
    int& c = image.compPerPixel;
    for (int i = up(image); i < bottom(image); i++) {
        for (int j = left(image); j < right(image); j++) {
            image.pixels[(i * image.w + j) * c] = image.pixels[(i * image.w + j) * c + 1] 
                = image.pixels[(i * image.w + j) * c + 2] = intensity(image, i, j);
        }
    }
    return true;
}
