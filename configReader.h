#pragma once
#include "png_toolkit.h"

class ConfigReader {
private:
    ifstream confFile;
public:
    ConfigReader(const char* confFileName);
    bool ReadNextFilter();

    image_data* ReadConfig(const char* confFile);
};