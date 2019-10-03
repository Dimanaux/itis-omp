#include <omp.h>
#include <stdio.h>

int minimum(int array[], int size) {
    int min = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int maximum(int array[], int size) {
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int main() {
    int a[] = {0, 2, 4, 6, 8, 10, 12, 3, -1, -5};
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    omp_set_num_threads(2);
    int min;
    int max;
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            min = minimum(a, 10);
        }

        #pragma omp section
        {
            max = maximum(b, 10);
        }
    }
    printf("min of a = %d, max of b = %d\n", min, max);
}
