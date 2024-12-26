#include <time.h>
#include <stdlib.h>
#include "file_manager.h"

double bubble_sort(int *array, int size){
    clock_t end_time, start_time = clock();

    int temp;
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1; j++){
            if (array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    end_time = clock();
    double time_out = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    return time_out;
}