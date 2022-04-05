void MySaxpy(int n, float a, float *X, float *Y)
{
//#pragma ivdep
//#pragma omp simd
//#pragma omp parallel for
//#pragma vector nodynamic_align
    for (int i = 0; i < n; ++i)
        Y[i] = a * X[i] + Y[i];
}

