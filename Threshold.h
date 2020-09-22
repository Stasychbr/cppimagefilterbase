#include "Filter.h"

class Threshold :public Filter {
public:
	Threshold(int up, int left, int bottom, int right);
	virtual bool run(image_data& image);
};