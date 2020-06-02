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

//Função para registrar o resultado dos Metodos de um vetor de entrada ordenado em ordem crescente
void fileCrescente(double tempo, int n_compara, int n_movimento, char nomeMetodo[]){
    FILE *file;
    file = fopen("com112_relatorio_crescente.txt", "a");

    fprintf(file, "Metodo %s\n", nomeMetodo);
    fprintf(file, "   Tempo de execucao: %lf\n", tempo);
    fprintf(file, "   Numero de comparacoes: %d\n", n_compara);
    fprintf(file, "   Numero de movimentacoes: %d\n\n", n_movimento);
    fclose(file);
}

//Função para registrar o resultado dos metodos de um vetor de entrada ordenado em ordem decrescente
void fileDecrescente(double tempo, int n_compara, int n_movimento, char nomeMetodo[]){
    FILE *file;
    file = fopen("com112_relatorio_decrescente.txt", "a");

    fprintf(file, "Metodo %s\n", nomeMetodo);
    fprintf(file, "   Tempo de execucao: %lf\n", tempo);
    fprintf(file, "   Numero de comparacoes: %d\n", n_compara);
    fprintf(file, "   Numero de movimentacoes: %d\n\n", n_movimento);
    fclose(file);
}


//Função para registrar o resultado dos metodos em com112_relatorio.txt
void fileRelatorio(double tempo, int n_compara, int n_movimento, char nomeMetodo[]){
    FILE *file, *file2;
    file = fopen("com112_relatorio.txt", "a");

    fprintf(file, "Metodo %s\n", nomeMetodo);
    fprintf(file, "   Tempo de execucao: %lf\n", tempo);
    fprintf(file, "   Numero de comparacoes: %d\n", n_compara);
    fprintf(file, "   Numero de movimentacoes: %d\n\n", n_movimento);

    file2 = fopen("com112_relatorio_aleatorio.txt", "a");

    fprintf(file2, "Metodo %s\n", nomeMetodo);
    fprintf(file2, "   Tempo de execucao: %lf\n", tempo);
    fprintf(file2, "   Numero de comparacoes: %d\n", n_compara);
    fprintf(file2, "   Numero de movimentacoes: %d\n\n", n_movimento);

    fclose(file);
    fclose(file2);
}

//Função para registrar os elementos gerados aleatóriamente no arquivo com112_entrada.txt e iniciando com112_relatorio.txt
void fileEntrada(int *V, int n){
    FILE *file, *file1, *file2, *file3, *file4;
    file = fopen("com112_entrada.txt", "w");
    fprintf(file, "%d\n", n);
    for(int i = 0; i < n; i++){
        fprintf(file, "%d ", V[i]);
    }

    file1 = fopen("com112_relatorio.txt", "w");
    fprintf(file1, "Numero de elementos ordenados: %d\n\n", n);

    file2 = fopen("com112_relatorio_aleatorio.txt", "w");
    fprintf(file2, "Numero de elementos ordenados: %d\n\n", n);

    file3 = fopen("com112_relatorio_crescente.txt", "w");
    fprintf(file3, "Numero de elementos ordenados: %d\n\n", n);

    file4 = fopen("com112_relatorio_decrescente.txt", "w");
    fprintf(file4, "Numero de elementos ordenados: %d\n\n", n);

    fclose(file);
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(file4);
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

