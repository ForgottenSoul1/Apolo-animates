//
// Created by serba on 11/13/2026.
//

#ifndef APOLO_ANIMATES_PIXEL_H
#define APOLO_ANIMATES_PIXEL_H

#include "fixed_point_1_15.h"

typedef struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    FixedPoint_1_15 opacity;
} Pixel;

namespace PIXEL {
    const Pixel RED={255,0,0, FIXED_POINT_1_15::ONE};
    const Pixel GREEN={0,255,0, FIXED_POINT_1_15::ONE};
    const Pixel BLUE={0,0,255, FIXED_POINT_1_15::ONE};
    const Pixel WHITE={255,255,255,FIXED_POINT_1_15::ONE};
    const Pixel BLACK={0,0,0,FIXED_POINT_1_15::ONE};
    const Pixel YELLOW={255,255,0,FIXED_POINT_1_15::ONE};
    const Pixel MAGENTA={255,0,255,FIXED_POINT_1_15::ONE};
    const Pixel CYAN={0,255,255,FIXED_POINT_1_15::ONE};
    const Pixel EMPTY={0,0,0,FIXED_POINT_1_15::ZERO};
}

FixedPoint_1_15 probabilityAnd (FixedPoint_1_15 A, FixedPoint_1_15 B);
FixedPoint_1_15 probabilityOr  (FixedPoint_1_15 A, FixedPoint_1_15 B);
FixedPoint_1_15 probabilityNot (FixedPoint_1_15 A);

#endif //APOLO_ANIMATES_PIXEL_H
