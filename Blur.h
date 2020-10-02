#pragma once
#include "Convolutional.h"

class Blur :private Convolutional {
private:
    static const int _weights[Convolutional::wSize()][Convolutional::wSize()];
protected:
    virtual int weight(int i, int j) override { return _weights[i][j]; };
public:
    Blur(int up, int left, int bottom, int right);
};