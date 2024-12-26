#include <stdio.h>
#include <time.h>
#include <string.h>
#include "file_manager.h"
#include "combination_generator.h"
#include "insertion_sort.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"

// instruções para inserir novo algoritmo:
// acrescentar na main
// adicionar texto em process_file()
// adicionar em get_algorithm_name()
// adicionar texto para nome do arquivo em generate_filename()

int main(){

    char order, algorithm; 
    int max_size;

    do{
        do {
            printf("\ni - Insertion Sort\nb - Bubble Sort\ns - Selection Sort\nh - Shell Sort\nm - Merge Sort\ne - Sair\n");
            scanf(" %c", &algorithm);
            fflush(stdin);
        } while (algorithm != 'i' && algorithm != 'b' && algorithm != 's' && algorithm != 'h' && algorithm != 'm' && algorithm != 'e');
        if (algorithm == 'e') break;

        create_folders(algorithm);

        do{
            printf("Escolha o tamanho maximo:\n1 - 10\n2 - 100\n3 - 1000\n4 - 10000\n5 - 100000\n6 - 1000000\n");
            scanf("%d", &max_size);
            fflush(stdin);
        }while (max_size != 1 && max_size != 2 && max_size != 3 && max_size != 4 && max_size != 5 && max_size != 6);

        do{
            printf("\nr - Random\nc - Crescente\nd - Decrescente\nt - Todos\ne - Sair\n");
            scanf(" %c", &order);
        }while (order != 'r' && order != 'c' && order != 'd' && order != 't' && order != 'e');
        if (order == 'e') break;
        switch(order){
            case 'r':
                create_array(order, algorithm, max_size);
                break;
            
            case 'c':
                create_array(order, algorithm, max_size);
                break;

            case 'd':
                create_array(order, algorithm, max_size);
                break;

            case 't':
                create_array('c', algorithm, max_size);
                create_array('r', algorithm, max_size);
                create_array('d', algorithm, max_size);
                return 0;

            case 'e':
                printf("Programa finalizado.\n");
                break;
        }   
        fflush(stdin);
    }while(order != 'e');
    return 0;
}