#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float** read_csv(const char* filename, int* rows, int* cols) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return NULL;
    }

    char line[1024];
    int row_count = 0;
    int col_count = 0;
    float** data = NULL;

    if (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            col_count++;
            token = strtok(NULL, ",");
        }
    }

    data = (float**)malloc(sizeof(float*) * 100);
    if (data == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(file);
        return NULL;
    }

    while (fgets(line, sizeof(line), file)) {
        if (row_count >= 100) {
            data = (float**)realloc(data, sizeof(float*) * (row_count + 100));
            if (data == NULL) {
                printf("Erro ao realocar memória\n");
                fclose(file);
                return NULL;
            }
        }

        data[row_count] = (float*)malloc(sizeof(float) * col_count);
        if (data[row_count] == NULL) {
            printf("Erro ao alocar memória para linha %d\n", row_count);
            fclose(file);
            return NULL;
        }

        int col_index = 0;
        char* token = strtok(line, ",");
        while (token != NULL) {
            data[row_count][col_index++] = atof(token);
            token = strtok(NULL, ",");
        }

        row_count++;
    }

    *rows = row_count;
    *cols = col_count;
    fclose(file);
    return data;
}
