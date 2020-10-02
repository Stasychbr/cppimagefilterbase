#include "Convolutional.h"

Convolutional::Convolutional(int up, int left, int bottom, int right): BlackWhite(up, left, bottom, right) {
}

unsigned char Convolutional::getConvolution(int row, int col, image_data& image) {
    float res = 0;
    float sum = 0;
    for (int i = 0; i < _wSize; i++) {
        for (int j = 0; j < _wSize; j++) {
            int pixX = i + row - _wSize / 2;
            int pixY = j + col - _wSize / 2;
            if (pixX >= up(image) && pixX < bottom(image) && pixY >= left(image) && pixY < right(image)) {
                int pixPos = (pixX * image.w + pixY) * image.compPerPixel;
                res += weight(i, j) * image.pixels[pixPos + j];
                sum += weight(i, j);
            }
        }
    }
    res /= sum;
    return (unsigned char) res;
}
