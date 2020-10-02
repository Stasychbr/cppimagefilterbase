#include "Blur.h"

const float Blur::_weights[Convolutional::wSize()][Convolutional::wSize()] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };

Blur::Blur(int up, int left, int bottom, int right) : Convolutional(up, left, bottom, right) {
}

