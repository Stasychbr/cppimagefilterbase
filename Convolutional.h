#pragma once
#include "BlackWhite.h"
#include <vector>
#include <array>

class Convolutional:public Filter {
private:
    //std::vector<std::vector<float>> _weights;
    static const int _wSize = 3;
    int _wSum = 0;
protected:
    Convolutional(int up, int left, int bottom, int right);
    std::vector<unsigned char> getConvolution(int row, int col, image_data& image);
    constexpr static int wSize() { return _wSize; };
    virtual int weight(int row, int col) = 0;
};