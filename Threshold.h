#pragma once
#include "Filter.h"
#include "BlackWhite.h"
#include <vector>

class Threshold :private BlackWhite {
	std::vector<unsigned char> pixMatrix(image_data& image, int row, int col);
public:
	Threshold(int up, int left, int bottom, int right);
	virtual bool run(image_data& image);
};