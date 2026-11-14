//
// Created by serba on 11/13/2026.
//

#include "pixel.h"

extern inline FixedPoint_1_15 probabilityAnd (FixedPoint_1_15 A, FixedPoint_1_15 B) {
    return multiply(A, B);
}

extern inline FixedPoint_1_15 probabilityOr (FixedPoint_1_15 A, FixedPoint_1_15 B) {
    return FIXED_POINT_1_15::ONE - multiply(FIXED_POINT_1_15::ONE - A, FIXED_POINT_1_15::ONE - B);
}

extern inline FixedPoint_1_15 probabilityNot (FixedPoint_1_15 A) {
    return FIXED_POINT_1_15::ONE - A;
}
