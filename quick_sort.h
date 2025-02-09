#include <stdlib.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// pivô ao final
int partition_v1(int arr[], int left, int right){
    int pivot_value = arr[right];
    int i = left; 

    for (int j = left; j < right; j++){
        if (arr[j] <= pivot_value){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    
    swap(&arr[i], &arr[right]);

    return i;
}

void quick_sort_v1(int arr[], int left, int right){
    if (left < right){
        int index = partition_v1(arr, left, right);
        quick_sort_v1(arr, left, index - 1);
        quick_sort_v1(arr, index + 1, right);
    }
}

// pivô centralizado
void quick_sort_v2(int arr[], int left, int right){
    int i = left;
    int j = right - 1;
    int pivot = arr[(left + right) / 2];

    while (i <= j){
        while(arr[i] < pivot && i < right) i++;
        while(arr[j] > pivot && j > left) j--;

        if (i <= j){
            swap(&arr[i], &arr[j]);

            i++;
            j--;
        }
    }

    if (j > left)   quick_sort_v2(arr, left, j + 1);
    if (i < right)  quick_sort_v2(arr, i, right);
}

//Pivô aleatório
int partition_v3(int arr[], int left, int right) {
    int pivot_index = left + rand() % (right - left + 1);
    
    swap(&arr[pivot_index], &arr[right]);

    int pivot_value = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot_value) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);

    return i;
}

void quick_sort_v3(int arr[], int left, int right) {
    if (left < right) {
        int index = partition_v3(arr, left, right);
        quick_sort_v3(arr, left, index - 1);
        quick_sort_v3(arr, index + 1, right);
    }
}

//#######################################################################//

double intermediate_quick(int arr[], int left, int right, int type) { 

    clock_t end_time, start_time = clock();


    // em caso de entrada inválida, executará o quick sort - pivô central
    switch (type){
        case 0:     quick_sort_v1(arr, left, right);    break;
        case 1:     quick_sort_v2(arr, left, right);    break;
        case 2:     quick_sort_v3(arr, left, right);    break;
        default:    quick_sort_v2(arr, left, right);    break;
    }

    end_time = clock();
    double time_out = (double)(end_time - start_time)/CLOCKS_PER_SEC;

    return time_out;
}