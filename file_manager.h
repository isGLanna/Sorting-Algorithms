#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdio.h>
#include <string.h>
#include <direct.h>
#include <errno.h>

// numeração 1, 2, 3 para gerar arquivo .txt de TEMPO: crescente, random e decrescente

// Escreve arquivo .txt
void write_archive(double time, int *array, int size_array, char *archive_name){
    FILE * arquivo;
    printf("%s\n", archive_name);

    arquivo = fopen(archive_name, "w");

    if (!arquivo){
        printf("Falha ao criar arquivo.\n");
        return;
    }

    // verifica se variavel tempo foi recebida para printar em arquivo separado
    if(time != -1)
        fprintf(arquivo, "%f", time);
    else{
        int i = 0;
        while (i < size_array){
            fprintf(arquivo, "%d\n", array[i]);
            i++;
        }
    }
    printf("Fechou o arquivo.\n");
    fclose(arquivo);
}


// retorna nome do algoritmo pela letra de entrada
const char* get_algorithm_name(char algorithm) {
    switch (algorithm) {
        case 'i': return "Insertion Sort";
        case 'b': return "Bubble Sort";
        case 's': return "Selection Sort";
        case 'h': return "Shell Sort";
        case 'm': return "Merge Sort";
    }
}

// Função única para gerar nomes de arquivos
char *generate_filename(char algorithm, char type, int size, char *text) {
    char size_string[15];
    sprintf(size_string, "%d.txt", size);

    // Definindo o prefixo do algoritmo
    const char * algorithm_text = get_algorithm_name(algorithm);

    // Local de salvamento baseado no tipo
    if (type == 'r') {
        sprintf(text, "%s/Arquivo de saida/Random/SaidaRandom", algorithm_text);
    } else if (type == '1') {
        sprintf(text, "%s/Arquivo de tempo/Random/TempoRandom", algorithm_text);
    } else if (type == 'c') {
        sprintf(text, "%s/Arquivo de saida/Crescente/SaidaCrescente", algorithm_text);
    } else if (type == '2') {
        sprintf(text, "%s/Arquivo de tempo/Crescente/TempoCrescente", algorithm_text);
    } else if (type == 'd') {
        sprintf(text, "%s/Arquivo de saida/Decrescente/SaidaDecrescente", algorithm_text);
    } else {
        sprintf(text, "%s/Arquivo de tempo/Decrescente/TempoDecrescente", algorithm_text);
    }

    strcat(text, size_string);
    return text;
}


// Cria as pastas
void create_folders(char algorithm) {
    char folder[200];

    const char *algorithm_name = get_algorithm_name(algorithm);

    sprintf(folder, "%s", algorithm_name);
    _mkdir(folder);
    sprintf(folder, "%s\\Arquivo de entrada", algorithm_name);
    _mkdir(folder);
    sprintf(folder, "%s\\Arquivo de saida", algorithm_name);
    _mkdir(folder);
    sprintf(folder, "%s\\Arquivo de tempo", algorithm_name);
    _mkdir(folder);

    char *order[] = {"Random", "Crescente", "Decrescente"};

    for(int i = 0; i < 3; i++){
        sprintf(folder, "%s\\Arquivo de entrada\\%s", algorithm_name, order[i]);
        _mkdir(folder);

        sprintf(folder, "%s\\Arquivo de saida\\%s", algorithm_name, order[i]);
        _mkdir(folder);

        sprintf(folder, "%s\\Arquivo de tempo\\%s", algorithm_name, order[i]);
        _mkdir(folder);
    }
}

#endif //FILE_MANAGER_H