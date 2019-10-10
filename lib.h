#include <cstdio>
#include <cstdlib>
#include <ctime>

const int ARRAY_MAX_VALUE = 1000;

bool seedIsSet = false;

void setRandomSeed() {
    if (!seedIsSet) {
        srand(time(NULL));
        seedIsSet = true;
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print2dArray(int** array, int size, int innerSize) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < innerSize; j++) {
            printf("%*d", 4, array[i][j]);
        }
        printf("\n");
    }
}

int* randomArray(int size) {
    setRandomSeed();
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % ARRAY_MAX_VALUE;
    }
    return array;
}

int** random2dArray(int rows, int cols) {
    setRandomSeed();
    int** arrays = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arrays[i] = randomArray(cols);
    }
    return arrays;
}
