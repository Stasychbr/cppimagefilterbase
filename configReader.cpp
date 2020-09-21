#include "configReader.h"
#include <fstream>
#include <string.h>
#include "Red.h"
using namespace std;

const char* ConfigReader::redFilterName = "Red";
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
        sscanf(line, "%i %i %i %i", &u, &l, &b, &r);
        return (Filter*)new Red(u, l, b, r);
    }
    else {
        return nullptr;
    }
}
