#include <cstdio>
#include <omp.h>

#include "lib.h"

int main() {
    const int n = 6;
    const int m = 8;
    int** d = random2dArray(n, m);

    int min = d[0][0];
    int max = d[0][0];

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            #pragma omp critical
            if (d[i][j] < min) {
                min = d[i][j];
            }

            #pragma omp critical
            if (d[i][j] > max) {
                max = d[i][j];
            }
        }
    }

    print2dArray(d, n, m);
    printf("min=%d, max=%d\n", min, max);
}
