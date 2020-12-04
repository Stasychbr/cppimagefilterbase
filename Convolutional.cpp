#include "Convolutional.h"

using namespace std;

Convolutional::Convolutional(int up, int left, int bottom, int right): Filter(up, left, bottom, right) {
}

vector<unsigned char> Convolutional::getConvolution(int row, int col, image_data& image) {
    int conv = 0;
    vector<unsigned char> res(3);
    if (_wSum == 0) {
        for (int i = 0; i < _wSize; i++) {
            for (int j = 0; j < _wSize; j++) {
                _wSum += weight(i, j);
            }
        }
    }
    for (int color = 0; color < 3; color++) {
        conv = 0;
        for (int i = 0; i < _wSize; i++) {
            for (int j = 0; j < _wSize; j++) {
                int pixX = i + row - _wSize / 2;
                int pixY = j + col - _wSize / 2;
                if (pixX >= up(image) && pixX < bottom(image) && pixY >= left(image) && pixY < right(image)) {
                    int pixPos = (pixX * image.w + pixY) * image.compPerPixel;
                    conv += weight(i, j) * image.pixels[pixPos + color];
                }
            }
        }
        conv /= _wSum;
        res[color] = (unsigned int)conv;
    }
    return res;
}

//bool Convolutional::run(image_data& image) {
//    if (!BlackWhite::run(image)) {
//        return false;
//    }
//    std::vector<unsigned int> newPixs;
//    for (int i = up(image); i < bottom(image); i++) {
//        for (int j = left(image); j < right(image); j++) {
//            newPixs.push_back(getConvolution(i, j, image));
//        }
//    }
//    auto pixIter = newPixs.begin();
//    int& c = image.compPerPixel;
//    int& w = image.w;
//    for (int i = up(image); i < bottom(image); i++) {
//        for (int j = left(image); j < right(image); j++) {
//            image.pixels[(i * w + j) * c] = image.pixels[(i * w + j) * c + 1] = image.pixels[(i * w + j) * c + 2] = *pixIter;
//            pixIter++;
//        }
//    }
//    return true;
//}
