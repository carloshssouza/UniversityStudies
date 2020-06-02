#include <stdlib.h>
#include <stdio.h>
#include "com112_sort.h"
#include <math.h>


//Função para o método Selection Sort
void selectionSort(int *V, int *n_compara, int *n_movimento, int n){
    int menor;
    int troca;

    for(int i = 0; i < n-1; i++){
        menor = i;

        for(int j = i+1; j < n; j++){
            //contando a quantidade de comparações de elementos realizadas para a ordenação
            *n_compara += 1;
            if(V[j] < V[menor]){
                menor = j;
            }

        }
        if(i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;

            //contando a quantidade de movimentos realizados pela troca de posição
            *n_movimento += 1;
        }
        *n_movimento += 1;
    }
}

void bubbleDecrescente(int *V, int n){
    int aux;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            if(V[j] < V[j+1]){
                aux = V[j];
                V[j] = V[j+1];
                V[j+1] = aux;
            }
        }
    }
}
//Função para o método Bubble Sort
void bubbleSort(int *V, int *n_compara, int *n_movimento, int n){
    int aux;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            //contador a quantidade de comparações de elementos para a ordenação
            *n_compara += 1;

            if(V[j] > V[j+1]){
                aux = V[j];
                V[j] = V[j+1];
                V[j+1] = aux;

                //contando a quantidade de movimentos realizados pela troca de posição
                *n_movimento += 1;
            }
        }
    }
}

//Função para o método Insertion Sort
void insertionSort(int *V, int *n_compara, int *n_movimento, int n){
    int aux;
    int j;

    for(int i = 1; i < n; i++){
        aux = V[i];
        //Contando a comparação inicial
        *n_compara += 1;
        for(j = i; (j > 0) && (aux < V[j-1]); j--){
            V[j] = V[j-1];

            //contando a quantidade de movimentos realizados pela troca de posição
            *n_movimento += 1;
            //contando a quantidade de comparação de elementos para a ordenação
            *n_compara += 1;
        }
        V[j] = aux;
        *n_movimento += 2;

    }
}

void merge(int *V, int inicio, int meio, int fim, int *n_compara, int *n_movimento){
    int *temp, p1, p2, tamanho;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int*)malloc(tamanho * sizeof(int));
    if(temp != NULL){
        for(int i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                *n_compara = *n_compara + 1;
                if(V[p1] < V[p2]){
                    *n_movimento = *n_movimento + 1;
                    temp[i] = V[p1++];
                }else{
                    *n_movimento = *n_movimento + 1;
                    temp[i] = V[p2++];
                }

                if(p1>meio) fim1 = 1;
                if(p2>fim) fim2 = 1;
            }else{
                if(!fim1) {
                    *n_movimento = *n_movimento + 1;
                    temp[i] = V[p1++];
                }
                else{
                    *n_movimento = *n_movimento + 1;
                    temp[i] = V[p2++];
                }
            }
        }
        for(int j = 0, k = inicio; j < tamanho; j++, k++){
            V[k] = temp[j];
        }
    }
    free(temp);
}
void mergeSort(int *V, int *n_compara, int *n_movimento, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V, n_compara, n_movimento, inicio, meio);
        mergeSort(V, n_compara, n_movimento, meio+1, fim);
        merge(V, inicio, meio, fim, n_compara, n_movimento);
    }
}

//Função para
void troca(int *V, int i, int j, int *n_movimento){
    int aux;
    aux = V[i];
    V[i] = V[j];
    V[j] = aux;
    *n_movimento += 1;
}

int particiona(int *V, int p, int r, int *n_compara, int *n_movimento){
    int pivo, i, j;
    pivo = V[(p+r)/2];
    i = p-1;
    j = r+1;
    while(i < j){

        do{
            j = j - 1;
            *n_compara += 1;
        }while(V[j] > pivo);

        do{
            i = i + 1;
            *n_compara += 1;
        }while(V[i] < pivo);
        if(i < j) troca(V, i, j, n_movimento);
    }
    return j;
}
void quickSort(int *V, int p, int r, int *n_compara, int *n_movimento){
    int q;
    if(p < r){
        q = particiona(V, p, r, n_compara, n_movimento);
        quickSort(V, p, q, n_compara, n_movimento);
        quickSort(V, q+1, r, n_compara, n_movimento);
    }
}


