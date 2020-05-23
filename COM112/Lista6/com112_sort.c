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

//Função para o método Inserction Sort
void insertionSort(int *V, int *n_compara, int *n_movimento, int n){
    int aux;
    int j;
    for(int i = 0; i < n; i++){
        aux = V[i];
        //Contando a comparação inicial
        *n_compara = *n_compara + 1;
        for(j = i; (j > 0) && (aux < V[j-1]); j--){
            V[j] = V[j-1];

            //contando a quantidade de movimentos realizados pela troca de posição
            *n_movimento += 1;

            //contando a quantidade de comparação de elementos para a ordenação
            *n_compara = *n_compara + 1;
        }
        V[j] = aux;
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


int particiona(int *V, int *n_compara, int *n_movimento, int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while(esq < dir){
        *n_compara = *n_compara + 2;
        while(V[esq] <= pivo){
            *n_compara = *n_compara + 1;
            esq++;
        }
        while(V[dir] > pivo){
            *n_compara = *n_compara + 1;
            dir--;
        }
        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
            *n_movimento = *n_movimento + 1;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    *n_movimento = *n_movimento + 1;
    return dir;
}
void quickSort(int *V, int *n_compara, int *n_movimento, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(V, n_compara, n_movimento, inicio, fim);
        quickSort(V, n_compara, n_movimento, inicio, pivo-1);
        quickSort(V, n_compara, n_movimento, pivo+1, fim);
    }
}