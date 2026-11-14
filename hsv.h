//
// Created by serba on 11/13/2026.
//

#ifndef APOLO_ANIMATES_HSV_H
#define APOLO_ANIMATES_HSV_H
#include "pixel.h"

typedef struct Hsv {
    double hue, saturation, value;
    FixedPoint_1_15 opacity;
} Hsv;

void rgbToHsv(const Pixel * rgb, Hsv * result);
void hsvToRgb(const Hsv* hsv, Pixel * result);

#endif //APOLO_ANIMATES_HSV_H
