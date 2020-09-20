#include "configReader.h"
#include <fstream>
using namespace std;

image_data* ReadConfig(const char* confFileName) {
    ifstream confFile(confFileName);
    image_data* imData = new image_data;
    if (!confFile.is_open() || !imData) {
        return nullptr;
    }

    return nullptr;
}

ConfigReader::ConfigReader(const char* confFileName) {

}
