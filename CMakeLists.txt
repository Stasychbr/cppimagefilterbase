cmake_minimum_required(VERSION 2.8)

project(student_toolkit)
add_executable(${PROJECT_NAME} "main.cpp" "png_toolkit.cpp" "png_toolkit.h"
    "stb_image.h" "stb_image_write.h" "Filter.cpp" "Filter.h" "configReader.cpp" "configReader.h" "Red.cpp" "Red.h" "Threshold.cpp" "BlackWhite.cpp" "Edge.cpp" "Edge.h" "Convolutional.h" "Convolutional.cpp" "Blur.cpp" "Blur.h")
