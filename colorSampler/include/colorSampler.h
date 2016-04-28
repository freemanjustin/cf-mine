// freeman.justin@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>


#define fail(...) colorsampler_fail(__LINE__,__func__,__FILE__,__VA_ARGS__)

typedef struct {

    int     width;
    int     height;
    char*   image;

}e;

// prototypes
void colorsampler_fail( const int, const char*, const char*, const char*, ... );
void RGBtoHSV( float r, float g, float b, float *h, float *s, float *v );
void HSVtoRGB( float *r, float *g, float *b, float h, float s, float v );
