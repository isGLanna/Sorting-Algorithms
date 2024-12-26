#include <time.h>
#include <stdlib.h>
#include "file_manager.h"

double shell_sort(int *array, int size){
    clock_t end_time, start_time = clock();

    int temp;
    for (int gap = size / 2; gap > 0; gap /= 2){

        for ( int i = gap; i < size; i++){
            temp = array[i];

            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap){
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }
    }

    end_time = clock();
    double time_out = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    return time_out;
}