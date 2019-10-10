#include <cstdio>
#include <omp.h>

#include "lib.h"

/**
 * 20000 x 20000
 * последовательное выполнение за 1.18 с
 * параллелизм на внешнем цикле 2.28 с (for)
 * параллелизм на внутреннем цикле 3.3 с (for reduction(+: s))
 */
int* multiply(int** matrix, int n, int m, int* vector) {
    int* result = new int[n];
    double t1 = omp_get_wtime();
    #pragma omp parallel for firstprivate(n, m, matrix, vector) schedule(static, 5000)
    for (int i = 0; i < n; i++) {
        int s = 0;
        // #pragma omp parallel for reduction(+: s)
        for (int j = 0; j < m; j++) {
            s += matrix[i][j] * vector[j];
        }
        result[i] = s;
    }
    double t2 = omp_get_wtime();
    printf("multiplied in %f s\n", (t2 - t1));
    return result;
}

int main() {
    int n = 20000;
    int m = 20000;

    int** matrix = random2dArray(n, m);
    int*  vector = randomArray(m);
    // printf("matrix:\n");
    // print2dArray(matrix, n, m);
    // printf("vector:\n");
    // printArray(vector, m);

    int* result = multiply(matrix, n, m, vector);

    // printf("result:\n");
    // printArray(result, n);
}

