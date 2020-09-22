#include <iostream>
#include "png_toolkit.h"
#include "Filter.h"
#include "configReader.h"

int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!
    try
    {
        if (argc != 4)
            throw "Not enough arguments";

        png_toolkit studTool;
        image_data image;
        ConfigReader cr(argv[1]);
        Filter* filter;
        if (!studTool.load(argv[2]))
            throw "Can't load the image";
        image = studTool.getPixelData();
        while (filter = cr.ReadNextFilter()) {
            filter->run(image);
            delete filter;
        }
        studTool.save(argv[3]);

    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
