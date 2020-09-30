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
    //unsigned char* bwImPix = new unsigned char[image.w * image.h * image.compPerPixel];
    /*if (!bwImPix) {
        return false;
    }*/
    //memcpy(bwImPix, image.pixels, image.w * image.h * image.compPerPixel);
    /*image_data bwIm;
    bwIm.compPerPixel = image.compPerPixel;
    bwIm.h = image.h;
    bwIm.w = image.w;
    bwIm.pixels = bwImPix;*/
    if (!BlackWhite::run(image)) {
        return false;
    }
    std::vector<int> toErase;
    for (int i = up(image); i < bottom(image); i++) {
        for (int j = left(image); j < right(image); j++) {
            std::vector<unsigned char> intensMatrix = pixMatrix(image, i, j);
            unsigned char curIntense = image.pixels[(i * image.w + j) * image.compPerPixel]; 
            //unsigned char median;
            int size = (int)intensMatrix.size();
            //std::sort(intensMatrix.begin(), intensMatrix.end());
            /*if (intensMatrix.size() % 2 == 0) {
                median = (intensMatrix[size / 2] + intensMatrix[size / 2 - 1]) / 2;
            }
            else {
                median = intensMatrix[size / 2];
            }*/
            std::nth_element(intensMatrix.begin(), intensMatrix.begin() + size / 2, intensMatrix.end());
            if (curIntense < intensMatrix[size / 2]) {
                //image.pixels[(i * w + j) * c] = image.pixels[(i * w + j) * c + 1] = image.pixels[(i * w + j) * c + 2] = 0;*/
                toErase.push_back((i * image.w + j) * image.compPerPixel);
                //toErase.push_back((i * w + j) * c + 1);
                //toErase.push_back((i * w + j) * c + 2);
            }
        }
    }
    for (auto pixel : toErase) {
        image.pixels[pixel] = image.pixels[pixel + 1] = image.pixels[pixel + 2] = 0;
    }
    //delete[] bwImPix;
    return true;
}
