#include <math.h>

float fast_inverse_sqrt(float x) {
    long i = *(long*)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(float*)&i;

    x = x * (1.5f - (x * x * 0.5f * x));
    return x;
}

void normalize_feature_vector_newton(float* features, int length) {
    for (int i = 0; i < length; i++) {
        features[i] = features[i] * fast_inverse_sqrt(features[i]);
    }
}

#include <xmmintrin.h>

void normalize_feature_vector_sse(float* features, int length) {
    for (int i = 0; i < length; i++) {
        __m128 val = _mm_load_ss(&features[i]);
        __m128 inv_sqrt = _mm_rsqrt_ss(val);  // Estimativa rápida da raiz quadrada inversa
        _mm_store_ss(&features[i], inv_sqrt);
    }
}
