cmake_minimum_required(VERSION 4.3)
project(Apolo_animates)

set(CMAKE_CXX_STANDARD 14)

add_executable(Apolo_animates
        main.cpp
        fixed_point_1_15.cpp
        fixed_point_1_15.h
        pixel.cpp
        pixel.h
        pixel_endofunctions.cpp
        pixel_endofunctions.h
        hsv.cpp
        hsv.h
        "raster_canvas.cpp"
        "raster_canvas.h"
        computation_node.cpp
        computation_node.h
)
