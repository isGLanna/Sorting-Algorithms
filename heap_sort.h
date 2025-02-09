#include <stdlib.h>
#include <stdio.h>


void troca(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// exibe o arranjo
void printar(int arr[], int size, int type) {
    switch (type){
        case 1:
            printf("Vetor original:\n");
            break;
        case 2:
            printf("Chamado a build:\n");
            break;
        case 3:
            printf("Chamado o HeapSort:\n");
            break;
    }
    for (int i = 0; i < size; i++)  printf("%d ", arr[i]);
    printf("\n");
}

// Heap máximo
void heapify_max(int arr[], int size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < size && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        troca(&arr[i], &arr[largest]);
        heapify_max(arr, size, largest);
    }
}

// Constroi
void build_max_heap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify_max(arr, size, i);
    }
}

void heap_sort_max(int arr[], int size) {
    build_max_heap(arr, size);

    printar(arr, size, 2);

    for (int i = size - 1; i > 0; i--) {
        troca(&arr[0], &arr[i]);
        heapify_max(arr, i, 0);
    }
}

// Heap mínimo
void min_heapify(int arr[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[smallest]) {
        smallest = l;
    }

    if (r < size && arr[r] > arr[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        troca(&arr[i], &arr[smallest]);
        min_heapify(arr, size, smallest);
    }
}

// Constroi
void build_min_heap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        min_heapify(arr, size, i);
    }
}

void heap_sort_min(int arr[], int size) {
    build_min_heap(arr, size);

    printar(arr, size, 2);

    for (int i = size - 1; i > 0; i--) {
        troca(&arr[0], &arr[i]);
        min_heapify(arr, i, 0);
    }
}

//############################ FILA DE PRIORIDADE #################################//

int heap_minimum(int arr[]){
    printf("\n Retorno: %d\n", arr[0]);
    return arr[0];
}

int extract_heap_min(int arr[], int *size) {
    if (*size < 1) {
        printf("Erro\n");
        return INT_MIN;
    }
    int min = arr[0];
    arr[0] = arr[*size - 1];
    (*size)--;
    min_heapify(arr, *size, 0);
    return min;
}

// Aumenta o valor de uma chave no heap mínimo
void heap_increase_key(int arr[], int i, int key) {
    if (key < arr[i]) {
        printf("Erro.\n");
        return;
    }
    arr[i] = key;
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
        troca(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Insere uma nova chave no heap mínimo
void max_heap_insert(int arr[], int *size, int key) {
    (*size)++;
    arr[*size - 1] = INT_MIN;
    heap_increase_key(arr, *size - 1, key);
}

// loop principal da Fila de Prioridade
void queue_control_unit(int arr[], int *size) {
    int func;
    do {
        printf("\n\n>>>---------------------------------<<<\n\n");
        printf("0. Sair\n");
        printf("1. Heap Minimum\n");
        printf("2. Extract Heap Min\n");
        printf("3. Heap Increase Key\n");
        printf("4. Max Heap Insert\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &func);

        switch (func) {
            case 1:
                int trash;
                trash = heap_minimum(arr);
                break;
            case 2: {
                int min = extract_heap_min(arr, size);
                if (min != INT_MIN) {
                    printf("Elemento extraido: %d\n", min);
                }
                break;
            }
            case 3: {
                int index, key;
                printf("Digite o idice e a nova chave: ");
                scanf("%d %d", &index, &key);
                heap_increase_key(arr, index, key);
                break;
            }
            case 4: {
                int key;
                printf("Digite a chave a ser inserida: ");
                scanf("%d", &key);
                max_heap_insert(arr, size, key);
                break;
            }
            case 0:
                printf("Operacoes finalizadas\n");
                break;

            default:
                printf("Insira uma opcao invalida!\n");
                break;
        }
    } while (func != 0);
}

//#######################################################################//

double intermediate_heap(int arr[], int size, int type){
    int func;
    printf("\n\n>>>----------------------<<<\n\n0. Executar funcao Heap\n1. Executar Fila de Prioridade\n");
    scanf("%d", &func);
    if(!func){
        printar(arr, size, 1);
            
        clock_t end_time, start_time = clock();

        type ? heap_sort_max(arr, size): heap_sort_min(arr, size);

        end_time = clock();
        double time_out = (double)(end_time - start_time)/CLOCKS_PER_SEC;

        printar(arr, size, 3);
        printf("\n");

        return time_out;

    }else{
        queue_control_unit(arr, &size);
        return 0;
    }
}
