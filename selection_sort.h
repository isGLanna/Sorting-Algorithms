#include <time.h>
#include <stdlib.h>
#include "file_manager.h"

double selection_sort(int *array, int size){
    clock_t end_time, start_time = clock();

    for (int i = 0; i < size - 1; i++){
        int min = i;

        for (int j = i + 1; j < size; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }

    end_time = clock();
    double time_out = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    return time_out;
}