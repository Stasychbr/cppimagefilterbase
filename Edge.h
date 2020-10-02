#pragma once 
#include "Convolutional.h"

class Edge :private Convolutional {
private:
    static const int _weights[Convolutional::wSize()][Convolutional::wSize()];
protected:
    virtual int weight(int row, int col) override { return _weights[row][col]; };
public:
    Edge(int up, int left, int bottom, int right);
};