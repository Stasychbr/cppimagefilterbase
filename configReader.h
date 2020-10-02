#pragma once
#include "png_toolkit.h"
#include "Filter.h"
#include <fstream>

class ConfigReader {
private:
    static const char* redFilterName;
    static const char* blackWhiteFilterName;
    static const char* thresholdFilterName;
    static const char* blurFilterName;
    static const int lineBufSize;
    std::ifstream confFile;
public:
    ConfigReader(const char* confFileName);
    Filter* ReadNextFilter();
};