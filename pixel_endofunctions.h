//
// Created by serba on 11/13/2026.
//

#ifndef APOLO_ANIMATES_PIXEL_ENDOFUNCTIONS_H
#define APOLO_ANIMATES_PIXEL_ENDOFUNCTIONS_H

#include "pixel.h"

typedef void (*PixelUnaryEndofunction)(const Pixel * pixel, Pixel * result);
typedef void (*PixelBinaryEndofunction)(const Pixel * pixel1, const Pixel * pixel2, Pixel * result);
typedef void (*PixelMultiEndofunction)(const Pixel ** pixels, Pixel * result);

void invert(const Pixel* pixel, Pixel* result);

void overlay(const Pixel* top, const Pixel* bottom, Pixel* result);
void mask(const Pixel* mask, const Pixel* masked, Pixel* result);

void add(const Pixel* A, const Pixel* B, Pixel* result);
void subtract(const Pixel* A, const Pixel* B, Pixel* result);
void multiply(const Pixel* A, const Pixel* B, Pixel* result);
void divide(const Pixel* A, const Pixel* B, Pixel* result);
void mutiplyPocentage(const Pixel* A, const Pixel* B, Pixel* result);




#endif //APOLO_ANIMATES_PIXEL_ENDOFUNCTIONS_H
