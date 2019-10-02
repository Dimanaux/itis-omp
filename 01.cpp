#include <omp.h>
#include <stdio.h>

/**
 * Эта программа выводит "Hello World" 8 раз.
 * Вывод программы не зависит от числа потоков на машине,
 * т. к. оператор вывода атомарен и число потоков задаётся
 * программой.
 */
int main() {
    omp_set_num_threads(8);
    #pragma omp parallel
    {
        printf("Hello World\n");
    }
}
