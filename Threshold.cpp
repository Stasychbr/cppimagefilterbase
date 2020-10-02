#include "Threshold.h"
#include <algorithm>

Threshold::Threshold(int up, int left, int bottom, int right):BlackWhite(up, left, bottom, right) {}

std::vector<unsigned char> Threshold::pixMatrix(image_data& image, int row, int col) {
    std::vector<unsigned char> matrix;
    for (int i = row - 2; i <= row + 2; i++) {
        for (int j = col - 2; j <= col + 2; j++) {
            if (i >= up(image) && i < bottom(image) && j >= left(image) && j < right(image)) {
                matrix.push_back(image.pixels[(i * image.w + j) * image.compPerPixel]);
            }
        }
    }
    return matrix;
}

bool Threshold::run(image_data& image) {
    if (!BlackWhite::run(image)) {
        return false;
    }
    std::vector<int> toErase;
    for (int i = up(image); i < bottom(image); i++) {
        for (int j = left(image); j < right(image); j++) {
            std::vector<unsigned char> intensMatrix = pixMatrix(image, i, j);
            unsigned char curIntense = image.pixels[(i * image.w + j) * image.compPerPixel]; 
            int size = (int)intensMatrix.size();
            std::nth_element(intensMatrix.begin(), intensMatrix.begin() + size / 2, intensMatrix.end());
            if (curIntense < intensMatrix[size / 2]) {
                toErase.push_back((i * image.w + j) * image.compPerPixel);
            }
        }
    }
    for (auto pixel : toErase) {
        image.pixels[pixel] = image.pixels[pixel + 1] = image.pixels[pixel + 2] = 0;
    }
    return true;
}
