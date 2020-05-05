#include <stdlib.h>
#include <stdio.h>
#include "com112_file.h"


//Função para leitura do arquivo com112_entrada.txt e jogando os elementos lidos para um vetor
void fileLeitura(int *V2, int n){
    FILE *file;
    file = fopen("com112_entrada.txt", "r");

    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        getchar();
        exit(0);
    }
    fscanf(file, "%d", &n);
    for(int i = 0; i < n; i++){
        fscanf(file, "%d", &V2[i]);
    }
    fclose(file);

}

//Função para registrar o resultado do Bubble Sort em com112_relatorio.txt
void fileBubble(double tempo, int n_compara, int n_movimento){
    FILE *file;
    file = fopen("com112_relatorio.txt", "a");

    fprintf(file, "Metodo Bubble Sort\n");
    fprintf(file, "   Tempo de execucao: %lf\n", tempo);
    fprintf(file, "   Numero de comparacoes: %d\n", n_compara);
    fprintf(file, "   Numero de movimentacoes: %d\n", n_movimento);

    fclose(file);
}

//Função para registar o resultado do Selection Sort em com112_relatorio.txt
void fileSelection(double tempo, int n_compara, int n_movimento){
    FILE *file;
    file = fopen("com112_relatorio.txt", "a");

    fprintf(file, "Metodo Selection Sort\n");
    fprintf(file, "   Tempo de execucao: %lf\n", tempo);
    fprintf(file, "   Numero de comparacoes: %d\n", n_compara);
    fprintf(file, "   Numero de movimentacoes: %d\n", n_movimento);

    fclose(file);
}

//Função para registrar o resultado do Inserction Sort em com112_relatorio.txt
void fileInsertion(double tempo, int n_compara, int n_movimento){
    FILE *file;
    file = fopen("com112_relatorio.txt", "a");

    fprintf(file, "Metodo Insertion\n");
    fprintf(file, "   Tempo de execucao: %lf\n", tempo);
    fprintf(file, "   Numero de comparacoes: %d\n", n_compara);
    fprintf(file, "   Numero de movimentacoes: %d\n", n_movimento);

    fclose(file);
}

//Função para registrar os elementos gerados aleatóriamente no arquivo com112_entrada.txt e iniciando com112_relatorio.txt
void fileEntrada(int *V, int n){
    FILE *file, *file2;
    file = fopen("com112_entrada.txt", "w");
    fprintf(file, "%d\n", n);
    for(int i = 0; i < n; i++){
        fprintf(file, "%d ", V[i]);
    }
    fclose(file);

    file2 = fopen("com112_relatorio.txt", "w");
    fprintf(file2, "Número de elementos ordenados: %d\n", n);
    fclose(file2);
}

//Função para registrar os elementos já ordenados no arquivo com112_saida.txt
void fileSaida(int *V2, int n){
    FILE *file;
    file = fopen("com112_saida.txt", "w");
    fprintf(file, "%d\n", n);
    for(int i = 0; i < n; i++){
        fprintf(file, "%d ", V2[i]);
    }

    fclose(file);
}

