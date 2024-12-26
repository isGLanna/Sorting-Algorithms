#include <time.h>
#include "file_manager.h"

void merge(int array[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArray = (int *)malloc(n1 * sizeof(int));
    int *rightArray = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}


void merge_sort(int array[], int left, int right){
    if (left < right){
        int mid = left + (right - left)/2;

        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

double intermediate_merge(int array[], int left, int right){
    clock_t end_time, start_time = clock();

    merge_sort(array, left, right);

    end_time = clock();
    double time_out = (double)(end_time - start_time)/CLOCKS_PER_SEC;

    return time_out;
}