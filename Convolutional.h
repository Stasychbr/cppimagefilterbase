#pragma once
#include "Filter.h"
#include <vector>

class Convolutional:public Filter {
private:
    std::vector<std::vector<float>> _weights;
protected:
    Convolutional(int up, int left, int bottom, int right, int wSize, float* weights);
    unsigned char getConvolution(image_data& image, int row, int col);
};