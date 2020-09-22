#include "Convolutional.h"

Convolutional::Convolutional(int up, int left, int bottom, int right, int wSize, float* weights): Filter(up, left, bottom, right) {
    for (int i = 0; i < wSize; i++) {
        _weights.push_back(std::vector<float>{});
        for (int j = 0; j < wSize; j++) {
            _weights[i].push_back(weights[i * wSize + j]);
        }
    }
}

unsigned char Convolutional::getConvolution(image_data& image, int row, int col) {
    float res = 0;
    float sum = 0;
    for (int i = row - _weights.size() / 2; i <= row + _weights.size() / 2; i++) {
        for (int j = col - _weights.size() / 2; j <= col + _weights.size() / 2; j++) {
            if (i >= 0 && i < image.w && j >= 0 && j < image.h) {
                res += _weights[i - (row - _weights.size() / 2)][j - (col - _weights.size() / 2)] *
                    image.pixels[(i * image.w + j) * image.compPerPixel + j - (col - _weights.size() / 2)];
                sum += _weights[i - (row - _weights.size() / 2)][j - (col - _weights.size() / 2)];
            }
        }
    }
    res /= sum;
    return (unsigned char) res;
}
