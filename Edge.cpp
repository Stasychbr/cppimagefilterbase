#include "Edge.h"

const float Edge::_weights[Convolutional::wSize()][Convolutional::wSize()] = { {-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1} };


Edge::Edge(int up, int left, int bottom, int right) : Convolutional(up, left, bottom, right){
}
