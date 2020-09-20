#pragma once
#include "Filter.h"

class Red : public Filter {
public:
    Red(int up, int left, int bottom, int right);
    virtual bool run(image_data& image);
};