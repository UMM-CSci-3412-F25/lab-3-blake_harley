#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdio.h>
#include <stdlib.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
    int total_size = 0;
    for (int i = 0; i < num_arrays; ++i) {
        total_size = total_size + sizes[i];
    }

    int* merged_array = malloc(total_size * sizeof(int));

    int currIndex = 0;
    for (int i = 0; i < num_arrays; ++i) {
        for (int j = 0; j < sizes[i]; ++j) {
            merged_array[currIndex++] = values[i][j];
        }
    }

    return merged_array;
}

int main(void) {
    int num_arrays = 3;
    int sizes[] = {4, 2, 5};
    int a[] = {3, 2, 0, 5};
    int b[] = {8, 9};
    int c[] = {6, 3, 2, 0, 5};
    int* values[] = {a, b, c};

    int* result = array_merge(num_arrays, sizes, values);
    
    int total_size = 4 + 2 + 5;
    for (int i = 0; i < total_size; ++i) {
        printf("%d ", result[i]);
    }
    // printf("\n");

    free(result);
    return 0;
}
