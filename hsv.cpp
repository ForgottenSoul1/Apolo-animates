//
// Created by serba on 11/13/2026.
//

#include "hsv.h"

extern void rgbToHsv(const Pixel * rgb, Hsv * result) {

    result->opacity= rgb->opacity;
}

void hsvToRgb(const Hsv* hsv, Pixel * result) {
    
    result->opacity= hsv->opacity;
}
