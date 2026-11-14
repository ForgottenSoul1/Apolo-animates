//
// Created by serba on 11/13/2026.
//

#include "fixed_point_1_15.h"

extern inline FixedPoint_1_15 multiply(const FixedPoint_1_15 A, const FixedPoint_1_15 B) {
    return (uint16_t) ( ((uint32_t)A)* ((uint32_t)B) >> 15 );
}

extern inline double toDouble(FixedPoint_1_15 A) {
    return 1.0 * A / (1<<15);
}
