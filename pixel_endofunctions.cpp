//
// Created by serba on 11/13/2026.
//

#include "pixel_endofunctions.h"

extern void invert(const Pixel* pixel, Pixel* result) {
    result->red = 255 - pixel->red;
    result->green = 255 - pixel->green;
    result->blue = 255 - pixel->blue;
    result->opacity = pixel->opacity;
}

extern void overlay(const Pixel* bottom, const Pixel* top, Pixel* result) {
    if (bottom->opacity == FIXED_POINT_1_15::ZERO && top->opacity == FIXED_POINT_1_15::ZERO) {
        *result = PIXEL::EMPTY;
        return;
    }

    FixedPoint_1_15 probabilityBottom= probabilityAnd(bottom->opacity,probabilityNot(top->opacity));
    FixedPoint_1_15 probabilityTop= top->opacity;

    FixedPoint_1_15 bottomConstant= probabilityBottom/(probabilityBottom + probabilityTop);
    FixedPoint_1_15 topConstant= 1 - bottomConstant;

    result->red =   ( ((uint32_t)bottom->red   * (uint32_t)bottomConstant + FIXED_POINT_1_15::ONE/2)>>15 ) + ( ((uint32_t)top->red   * ((uint32_t)topConstant) + FIXED_POINT_1_15::ONE/2)>>15 );
    result->green = ( ((uint32_t)bottom->green * (uint32_t)bottomConstant + FIXED_POINT_1_15::ONE/2)>>15 ) + ( ((uint32_t)top->green * ((uint32_t)topConstant) + FIXED_POINT_1_15::ONE/2)>>15 );
    result->blue =  ( ((uint32_t)bottom->blue  * (uint32_t)bottomConstant + FIXED_POINT_1_15::ONE/2)>>15 ) + ( ((uint32_t)top->blue  * ((uint32_t)topConstant) + FIXED_POINT_1_15::ONE/2)>>15 );

    result->opacity = probabilityOr(bottom->opacity,top->opacity);
}

extern void mask(const Pixel* mask, const Pixel* masked, Pixel* result) {
    result->red = masked->red;
    result->green = masked->green;
    result->blue = masked->blue;

    result->opacity = multiply(mask->opacity, masked->opacity);
}

extern void add(const Pixel* A, const Pixel* B, Pixel* result) {
    if ( ((uint32_t)A->red)   + ((uint32_t)B->red) > 255 ) result->red=255;
    else result->red= A->red + B->red;
    if ( ((uint32_t)A->green) + ((uint32_t)B->green) > 255 ) result->green=255;
    else result->green= A->green + B->green;
    if ( ((uint32_t)A->blue)  + ((uint32_t)B->blue) > 255 ) result->blue=255;
    else result->blue= A->blue + B->blue;

    result->opacity = probabilityAnd(A->opacity,B->opacity);
}

extern void subtract(const Pixel* A, const Pixel* B, Pixel* result) {
    if ( ((uint32_t)A->red)   < ((uint32_t)B->red) ) result->red=0;
    else result->red= A->red - B->red;
    if ( ((uint32_t)A->green) < ((uint32_t)B->green) ) result->green=0;
    else result->green= A->green - B->green;
    if ( ((uint32_t)A->blue)  < ((uint32_t)B->blue) ) result->blue=0;
    else result->blue= A->blue - B->blue;

    result->opacity = probabilityAnd(A->opacity,B->opacity);
}

extern void mutiply(const Pixel* A, const Pixel* B, Pixel* result) {
    if ( ((uint32_t)A->red)   * ((uint32_t)B->red) > 255 ) result->red=255;
    else result->red= A->red * B->red;
    if ( ((uint32_t)A->green) * ((uint32_t)B->green) > 255 ) result->green=255;
    else result->green= A->green * B->green;
    if ( ((uint32_t)A->blue)  * ((uint32_t)B->blue) > 255 ) result->blue=255;
    else result->blue= A->blue * B->blue;

    result->opacity = probabilityAnd(A->opacity,B->opacity);
}

extern void divide(const Pixel* A, const Pixel* B, Pixel* result) {
    if (A->red==0 && B->red == 0 || A->green==0 && B->green == 0 || A->blue==0 && B->blue == 0) {
        *result= PIXEL::EMPTY;
        return;
    }

    if (B->red==0) result->red=255;
    else result->red= A->red / B->red;
    if (B->green==0) result->green=255;
    else result->green= A->green / B->green;
    if (B->blue==0) result->blue=255;
    else result->blue= A->blue / B->blue;

    result->opacity = probabilityAnd(A->opacity,B->opacity);
}

extern void mutiplyPocentage(const Pixel* A, const Pixel* B, Pixel* result) {
    result->red=   ( ((uint16_t)A->red)   * ((uint16_t)B->red) ) >> 8;
    result->green= ( ((uint16_t)A->green) * ((uint16_t)B->green) ) >> 8;
    result->blue=  ( ((uint16_t)A->blue)  * ((uint16_t)B->blue) ) >> 8;

    result->opacity = probabilityAnd(A->opacity,B->opacity);
}