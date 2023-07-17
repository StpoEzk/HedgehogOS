#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <float.h>
#include <math.h>

// Triple fuck //
// I fucking hate this function
// It's fucking fully copypast
// It's worth fucking refactoring

static int _int_to_string(int64_t x, char str[], int d){
    int i = 0;

	if(x == 0){
		str[i++] = '0';
	}

    while(x){
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    while(i < d){
        str[i++] = '0';
	}

	//reverse
	int k = 0, l = i - 1, temp;
    while(k < l){
        temp = str[k];
        str[k] = str[l];
        str[l] = temp;
        k++;
        l--;
    }

    str[i] = '\0';
    return i;
}

void dtoa(double n, char* res, int afterpoint){
    int ipart = (int)n;

    double fpart = n - (double)ipart;

    int i = _int_to_string(ipart, res, 0);

    if (afterpoint != 0){
        res[i] = '.';

        fpart = fpart * pow(10, afterpoint);

        _int_to_string((int64_t)fpart, res + i + 1, afterpoint);
    }
}

