#include "Convolutional.h"

Convolutional::Convolutional(int up, int left, int bottom, int right): BlackWhite(up, left, bottom, right) {
}

unsigned char Convolutional::getConvolution(int row, int col, image_data& image) {
    float res = 0;
    float sum = 0;
    for (int i = 0; i < _wSize; i++) {
        for (int j = 0; j < _wSize; j++) {
            int pixX = i + row;
            int pixY = j + col;
            if (pixX >= up(image) && pixX < bottom(image) && pixY >= left(image) && pixY < right(image)) {
                int pixPos = (pixX * image.w + pixY) * image.compPerPixel;
                res += weight(i, j) * image.pixels[pixPos];
                sum += weight(i, j);
            }
        }
    }
    res /= sum;
    return (unsigned char) res;
}

bool Convolutional::run(image_data& image) {
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
