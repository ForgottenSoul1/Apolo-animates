//
// Created by serba on 11/14/2026.
//

#ifndef APOLO_ANIMATES_RASTER_CANVAS_H
#define APOLO_ANIMATES_RASTER_CANVAS_H

#include <cstdlib>

#include "pixel.h"

typedef  struct RasterCanvas {
private:
    size_t width, height;
    Pixel ** array;

public:
    RasterCanvas(size_t width, size_t height) {
        array = (Pixel**) malloc(sizeof(Pixel*) * width);
        if (array == nullptr) return;

        for (size_t i = 0; i < width; i++) {
            array[i] = (Pixel*)calloc(height, sizeof(Pixel));
            if (array[i] == nullptr) {
                for (size_t j = 0; j < i; j++) {
                    free(array[j]);
                }
                free(array);
                return;
            }
        }

        this->width = width;
        this->height = height;
    }

    ~RasterCanvas(){
        for (size_t j = 0; j < width; j++) {
            free(array[j]);
        }
        free(array);
    }

    Pixel* getColumnX(size_t x) {
        return array[x];
    }

    size_t getWidth() {
        return width;
    }

    size_t getHeight() {
        return height;
    }
} RasterCanvas;

#endif //APOLO_ANIMATES_RASTER_CANVAS_H
