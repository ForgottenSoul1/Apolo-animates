//
// Created by serba on 11/13/2026.
//

#ifndef APOLO_ANIMATES_FIXED_POINT_1_15_H
#define APOLO_ANIMATES_FIXED_POINT_1_15_H

#include <cstdint>

typedef uint16_t FixedPoint_1_15;

namespace FIXED_POINT_1_15 {
    const FixedPoint_1_15 ZERO= 0;
    const FixedPoint_1_15 ONE= 0x8000;
}

FixedPoint_1_15 multiply(FixedPoint_1_15 A, FixedPoint_1_15 B);
double toDouble(FixedPoint_1_15 A);

#endif //APOLO_ANIMATES_FIXED_POINT_1_15_H
