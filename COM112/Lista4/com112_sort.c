#include <stdlib.h>
#include <stdio.h>
#include "com112_sort.h"


//Função para o método Selection Sort
void selectionSort(int *V, int *n_compara, int *n_movimento, int n){
    int menor;
    int troca;

    for(int i = 0; i < n-1; i++){
        menor = i;
        for(int j = i+1; j < n; j++){
            if(V[j] < V[menor]){
                menor = j;
            }
            //contando a quantidade de comparações de elementos realizadas para a ordenação
            *n_compara += 1;
        }
        if(i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;

            //contando a quantidade de movimentos realizados pela troca de posição
            *n_movimento += 1;
        }
    }
}

//Função para o método Bubble Sort
void bubbleSort(int *V, int *n_compara, int *n_movimento, int n){
    int aux;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            if(V[j] > V[j+1]){
                aux = V[j];
                V[j] = V[j+1];
                V[j+1] = aux;

                //contando a quantidade de movimentos realizados pela troca de posição
                *n_movimento += 1;
            }
            //contador a quantidade de comparações de elementos para a ordenação
            *n_compara += 1;
        }
    }
}

//Função para o método Inserction Sort
void insertionSort(int *V, int *n_compara, int *n_movimento, int n){
    int aux;
    int j;
    for(int i = 0; i < n; i++){
        aux = V[i];
        for(j = i; (j > 0) && (aux < V[j-1]); j--){
            V[j] = V[j-1];

            //contando a quantidade de comparação de elementos para a ordenação
            *n_compara += 1;
        }
        V[j] = aux;

        //contando a quantidade de movimentos realizados pela troca de posição
        *n_movimento += 1;
    }
}