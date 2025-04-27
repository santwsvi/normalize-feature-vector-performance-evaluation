#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void measure_performance(void (*func)(float*, int), float* features, int length) {
    struct rusage usage_start, usage_end;
    clock_t start_time, end_time;

    getrusage(RUSAGE_SELF, &usage_start);
    start_time = clock();

    func(features, length);

    end_time = clock();
    getrusage(RUSAGE_SELF, &usage_end);

    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %f segundos\n", elapsed_time);
    printf("Tempo de usuário: %f segundos\n", (double)(usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec));
    printf("Tempo de sistema: %f segundos\n", (double)(usage_end.ru_stime.tv_sec - usage_start.ru_stime.tv_sec));
    printf("Uso de memória: %ld KB\n", usage_end.ru_maxrss);
}
