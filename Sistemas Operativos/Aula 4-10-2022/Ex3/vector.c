#include <stdlib.h>
#include <math.h>

#include "vector.h"

vector* vector_new(double x, double y, double z){
    vector* a = (vector*) malloc(sizeof(vector));
    a->x = x;
    a->y = y;
    a->z = z;
    return a;
}

vector* vector_add(vector* a, vector* b){
    return vector_new(a->x + b->x, a->y + b->y, a->z + b->z);
}

vector* vector_sub(vector* a, vector* b){
    return vector_new(a->x - b->x, a->y - b->y, a->z - b->z);
}

vector* vector_scale(double x, vector* a){
    return vector_new(a->x * x, a->y * x, a->z * x);
}

vector* vector_vprod(vector* a, vector* b){
    return vector_new(a->y * b->z - a->z * b->y,
                      -(a->x * b->z - a->z * b->x),
                      a->x * b->y - a->y * b->x);
}

double vector_sprod(vector* a, vector* b){
    return(a->x * b->x + a->y * b->y + a->z * b->z);
}

double vector_mod(vector* a){
    return(sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}
