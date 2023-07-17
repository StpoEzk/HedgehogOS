#include <math.h>

double modf(double x, double* ptr){
	*ptr = (int)x;
	x = x - *ptr;
	return x;
}

float modff(float x, float* ptr){
    *ptr = (int)x;
    x = x - *ptr;
    return x;
}
