#include "Blur.h"

const float Blur::_weights[Convolutional::wSize()][Convolutional::wSize()] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };

Blur::Blur(int up, int left, int bottom, int right) : Convolutional(up, left, bottom, right) {
}

bool Blur::run(image_data& image) {
    if (!BlackWhite::run(image)) {
        return false;
    }
    std::vector<unsigned int> newPixs;
    for (int i = up(image); i < bottom(image); i++) {
        for (int j = left(image); j < right(image); j++) {
            newPixs.push_back(getConvolution(i, j, image));
        }
    }
    auto pixIter = newPixs.begin();
    int& c = image.compPerPixel;
    int& w = image.w;
    for (int i = up(image); i < bottom(image); i++) {
        for (int j = left(image); j < right(image); j++) {
            image.pixels[(i * w + j) * c] = image.pixels[(i * w + j) * c + 1] = image.pixels[(i * w + j) * c + 2] = *pixIter;
            pixIter++;
        }
    }
    return true;
}
