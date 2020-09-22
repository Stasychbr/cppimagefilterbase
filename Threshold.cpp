#include "Threshold.h"
#include <algorithm>

Threshold::Threshold(int up, int left, int bottom, int right):BlackWhite(up, left, bottom, right) {}

std::vector<unsigned char> Threshold::pixMatrix(image_data& image, int row, int col) {
    std::vector<unsigned char> matrix;
    for (int i = row - 2; i <= row + 2; i++) {
        for (int j = col - 2; j <= col + 2; j++) {
            if (i >= 0 && i < image.h && j >= 0 && j < image.w) {
                matrix.push_back(intensity(image, i, j));
            }
        }
    }
    return matrix;
}

bool Threshold::run(image_data& image) {
    if (!BlackWhite::run(image)) {
        return false;
    }
    for (int i = up(image); i < bottom(image); i++) {
        for (int j = left(image); j < right(image); j++) {
            std::vector<unsigned char> intensMatrix = pixMatrix(image, i, j);
            unsigned char curIntense = intensity(image, i, j);
            unsigned char median;
            int size = intensMatrix.size();
            std::nth_element(intensMatrix.begin(), intensMatrix.begin() + size / 2, intensMatrix.end());
            if (intensMatrix.size() % 2 == 0) {
                std::nth_element(intensMatrix.begin(), intensMatrix.begin() + size / 2 + 1, intensMatrix.end());
                median = (intensMatrix[size / 2] + intensMatrix[size / 2 + 1]) / 2;
            }
            else {
                median = intensMatrix[size / 2];
            }
            if (curIntense < median) {
                int& c = image.compPerPixel;
                int& w = image.w;
                image.pixels[(i * w + j) * c] = image.pixels[(i * w + j) * c + 1] = image.pixels[(i * w + j) * c + 2] = 0;
            }
        }
    }
    return true;
}
