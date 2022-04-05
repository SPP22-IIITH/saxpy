#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "helper.h"

#define DEFAULT_VECTOR_LENGTH 100000000 // million
// computing Y = aX + Y
int main(int argc, char *argv[])
{
    struct timeval calc;
    double calctime;
    int n;          // vector size
    double a = 0.8; // scalar value
    double gflops;
    float *X, *Y;

    if (argc > 1)
        n = atoi(argv[1]);
    else
        n = DEFAULT_VECTOR_LENGTH;

    gflops = 2.0 * n * 1e-09;

    X = (float *)malloc(n * sizeof(float));
    Y = (float *)malloc(n * sizeof(float));

    srand((unsigned)time(NULL));

    RandomVector(n, X);
    RandomVector(n, Y);

    tick(&calc);

    MySaxpy(n, a, X, Y);

    calctime = tock(&calc);

    printf("Gflops: %f\n", gflops / calctime);
    free(X);
    free(Y);
}
