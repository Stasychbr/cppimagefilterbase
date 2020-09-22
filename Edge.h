#pragma once 
#include "BlackWhite.h"

class Edge :private BlackWhite {
public:
    virtual bool run(image_data& image);
};