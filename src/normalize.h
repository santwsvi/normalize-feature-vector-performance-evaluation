// normalize.h

#ifndef NORMALIZE_H
#define NORMALIZE_H

// Declarações das funções de normalização
void normalize_feature_vector_newton(float* features, int length);
void normalize_feature_vector_sse(float* features, int length);
float fast_inverse_sqrt(float x);

#endif
