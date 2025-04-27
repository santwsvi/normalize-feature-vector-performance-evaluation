#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_csv.h"
#include "normalize.h"
#include "performance.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Uso: %s <csv_file> <vector_size> <version>\n", argv[0]);
        return -1;
    }

    char* filename = argv[1];
    int vector_size = atoi(argv[2]);
    char* version = argv[3];

    printf("Lendo CSV: %s\n", filename);
    int rows, cols;
    float** data = read_csv(filename, &rows, &cols);

    if (data == NULL) {
        return -1;
    }

    if (strcmp(version, "newton") == 0) {
        printf("Usando normalização Newton-Raphson\n");
        normalize_feature_vector_newton(data[0], vector_size);
    } else if (strcmp(version, "sse") == 0) {
        printf("Usando normalização SSE\n");
        normalize_feature_vector_sse(data[0], vector_size);
    } else {
        printf("Versão desconhecida: %s\n", version);
        return -1;
    }

    measure_performance(normalize_feature_vector_newton, data[0], vector_size);
    return 0;
}
