#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double insertion_sort(int *array, int size);
double bubble_sort(int *array, int size);
double selection_sort(int *array, int size);
double shell_sort(int *array, int size);
double intermediate_merge(int *array, int left, int right);
double intermediate_quick(int *array, int left, int right, int called);
double intermediate_heap(int *array, int size, int type);
void write_archive(double time, int *array, int size_array, char *archive_name);
const char* get_algorithm_name(char algorithm);


// Chama o algoritmo e cria as pastas
void process_file(char algorithm, char order, int *array, int size, int called){
    char text[80], text_1[100], text_2[100], order_t;
    double time_out;
    const char * algorithm_name = get_algorithm_name(algorithm);
    const char * order_name;

    if (order == 'r'){
        order_t = '1';
        order_name = "Random";
    } else if (order == 'c'){
        order_t = '2';
        order_name = "Crescente";
    } else {
        order_t = '3';
        order_name = "Decrescente";
    }
    
    // Cria o caminho do arquivo e escreve valores de entrada
    sprintf(text, "%s/Arquivo de entrada/%s/Entrada%s%d.txt", algorithm_name, order_name, order_name, size);
    write_archive(-1, array, size, text);

    // Executa o algoritmo de ordenação selecionado e captura o tempo de execução
    switch (algorithm) {
        case 'i':   time_out = insertion_sort(array, size); break;
        case 'b':   time_out = bubble_sort(array, size); break;
        case 's':   time_out = selection_sort(array, size); break;
        case 'h':   time_out = shell_sort(array, size); break;
        case 'm':   time_out = intermediate_merge(array, 0, size); break;
        case 'q':   time_out = intermediate_quick(array, 0, size, called); break;
        case 'H':   time_out = intermediate_heap(array, size, called); break;
    }

    // Gera nomes para os arquivos de saída
    generate_filename(algorithm, order, size, text_1);
    write_archive(-1, array, size, text_1);

    generate_filename(algorithm, order_t, size, text_2);
    write_archive(time_out, array, size, text_2);
}

// Cria tipo de array solicitado pelo usuário
void create_array(char order, char algorithm, int max_size, int called){
    int j;
    const int sizes[] = {10, 100, 1000, 10000, 100000, 1000000};
    char text[80], text_1[100], text_2[100];              // atenção com valor para evitar estouro de buffer em sprintf
    int *array;
    double time_out;


    switch(order){

        // valores aleatórios
        case 'r':
            srand(time(NULL));
            for (j = 0; j < max_size; j++){
                // aloca dinamicamente
                array = (int *)malloc(sizes[j] * sizeof(int));

                for (int i = 0; i < sizes[j]; i++){
                    array[i] = rand();
                }
                process_file(algorithm, order, array, sizes[j], called);
            }break;

        // valores crescentes
        case 'c':
            for (j = 0; j < max_size;j++){
                // aloca dinamicamente
                array = (int *)malloc(sizes[j] * sizeof(int));

                for (int i = 0; i < sizes[j]; i++){
                    array[i] = i;
                }
                process_file(algorithm, order, array, sizes[j], called);
            }break;

        // valores decrescentes
        case 'd':
            for (j = 0; j < max_size;j++){
                // aloca dinamicamente
                array = (int *)malloc(sizes[j] * sizeof(int));

                for (int i = 0; i < sizes[j]; i++){
                    array[i] = sizes[j] - i;
                    }
                process_file(algorithm, order, array, sizes[j], called);
            }break;
    }
    free(array);
}
