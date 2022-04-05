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

// Changes as per the problem
    gflops = 2.0 * n * 1e-09;

    X = (float *)malloc(n * sizeof(float));
    Y = (float *)malloc(n * sizeof(float));

    srand((unsigned)time(NULL));

    RandomVector(n, X);
    RandomVector(n, Y);

    tick(&calc);

    MySaxpy(n, a, X, Y);

    calctime = tock(&calc);

// Changes as per the problem
    float mem_bw = 8.0*n*1e-09/calctime;
    printf("Time (in milli-secs) %f\n", calctime*1000);
    printf("Memory Bandwidth (in GBytes/s): %f\n", mem_bw);
    printf("Compute Throughput (in GFlops/s): %f\n", gflops / calctime);
    free(X);
    free(Y);
}
