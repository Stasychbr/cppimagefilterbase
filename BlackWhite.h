#include "Filter.h"

class BlackWhite : public Filter {
public:
	BlackWhite(int up, int left, int bottom, int right);
	virtual bool run(image_data& image);
};