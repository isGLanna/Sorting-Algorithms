#include <time.h>
#include "file_manager.h"

double insertion_sort(int *array, int size){
    int i;

    clock_t end_time, start_time = clock();
        
    // insertion_sort
    for (int j = 1; j < size; j++){
        int temp = array[j];
        i = j - 1;
        while (array[i] > temp && i >= 0){
            array[i + 1] = array [i];
            array[i] = temp;
            i--;
        }
    }

    end_time = clock();

    double time_out = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    return time_out;
}