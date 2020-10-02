#pragma once 
#include "Convolutional.h"

class Edge :private Convolutional {
private:
    static const int _weights[Convolutional::wSize()][Convolutional::wSize()];
protected:
    virtual int weight(int i, int j) override { return _weights[i][j]; };
public:
    Edge(int up, int left, int bottom, int right);
};