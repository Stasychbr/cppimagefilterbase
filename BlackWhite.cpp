#include "BlackWhite.h"

BlackWhite::BlackWhite(int up, int left, int bottom, int right) :Filter(up, left, bottom, right) {}

bool BlackWhite::run(image_data& image) {
    if (!image.pixels) {
        return false;
    }
    int& c = image.compPerPixel;
    for (int i = up(image); i < bottom(image); i++) {
        for (int j = left(image); j < right(image); j++) {
            unsigned char& r = image.pixels[(i * image.w + j) * c];
            unsigned char& g = image.pixels[(i * image.w + j) * c + 1];
            unsigned char& b = image.pixels[(i * image.w + j) * c + 2];
            r = g = b = 0.3 * r + 0.6 * g + 0.1 * b;
        }
    }
    return true;
}
