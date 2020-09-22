#pragma once
#include "Filter.h"

class BlackWhite : public Filter {
protected:
	unsigned char intensity(image_data& image, int row, int col);
public:
	BlackWhite(int up, int left, int bottom, int right);
	virtual bool run(image_data& image);
};