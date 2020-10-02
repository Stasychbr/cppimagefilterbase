#pragma once
#include "Convolutional.h"

class Blur :private Convolutional {
private:
    static const int _weights[Convolutional::wSize()][Convolutional::wSize()];
protected:
    virtual int weight(int row, int col) override { return _weights[row][col]; };
public:
    Blur(int up, int left, int bottom, int right);
};