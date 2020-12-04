#include "Blur.h"
#include <vector>
using namespace std;

const int Blur::_weights[Convolutional::wSize()][Convolutional::wSize()] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };

Blur::Blur(int up, int left, int bottom, int right) : Convolutional(up, left, bottom, right) {
}

bool Blur::run(image_data& image) {
    vector<unsigned char> conv(3);
    image_data copyImage;
    copyImage.compPerPixel = image.compPerPixel;
    copyImage.h = image.h;
    copyImage.w = image.w;
    copyImage.pixels = new unsigned char[image.w * image.h * image.compPerPixel];
    for (int i = 0; i < image.h; i++) {
        for (int j = 0; j < image.w; j++) {
            for (int color = 0; color < 3; color++) {
                copyImage.pixels[(i * image.w + j) * image.compPerPixel + color] = 
                    image.pixels[(i * image.w + j) * image.compPerPixel + color];
            }
        }
    }
    for (int i = up(image); i < bottom(image); i++) {
        for (int j = left(image); j < right(image); j++) {
            conv = Convolutional::getConvolution(i, j, copyImage);
            for (int color = 0; color < 3; color++) {
                image.pixels[(i * image.w + j) * image.compPerPixel + color] = conv[color];
            }
        }
    }
    delete[] copyImage.pixels;
    return true;
}