#include "configReader.h"
#include <fstream>
#include <string.h>
#include "Red.h"
#include "BlackWhite.h"
#include "Threshold.h"
#include "Blur.h"
#include "Edge.h"
using namespace std;

const char* ConfigReader::redFilterName = "Red";
const char* ConfigReader::blackWhiteFilterName = "BlackWhite";
const char* ConfigReader::thresholdFilterName = "Threshold";
const char* ConfigReader::blurFilterName = "Blur";
const char* ConfigReader::edgeFilterName = "Edge";
const int ConfigReader::lineBufSize = 32;

ConfigReader::ConfigReader(const char* confFileName) {
    confFile.open(confFileName);
}

Filter* ConfigReader::ReadNextFilter() {
    if (!confFile.good()) {
        return nullptr;
    }
    char line[lineBufSize];
    int u = 0, l = 0, b = 0, r = 0;
    confFile.getline(line, lineBufSize);
    if (strstr(line, redFilterName)) {
        sscanf(line + strlen(redFilterName), "%i %i %i %i", &u, &l, &b, &r);
        return (Filter*)new Red(u, l, b, r);
    }
    else if (strstr(line, blackWhiteFilterName)) {
        sscanf(line + strlen(blackWhiteFilterName), "%i %i %i %i", &u, &l, &b, &r);
        return (Filter*)new BlackWhite(u, l, b, r);
    }
    else if (strstr(line, thresholdFilterName)) {
        sscanf(line + strlen(thresholdFilterName), "%i %i %i %i", &u, &l, &b, &r);
        return (Filter*)new Threshold(u, l, b, r);
    }
    else if (strstr(line, blurFilterName)) {
        sscanf(line + strlen(blurFilterName), "%i %i %i %i", &u, &l, &b, &r);
        return (Filter*)new Blur(u, l, b, r);
    }
    /*else if (strstr(line, edgeFilterName)) {
        sscanf(line + strlen(edgeFilterName), "%i %i %i %i", &u, &l, &b, &r);
        return (Filter*)new Edge(u, l, b, r);
    }*/
    else {
        return nullptr;
    }
}
