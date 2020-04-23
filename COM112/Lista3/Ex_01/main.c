#include <stdio.h>
#include <stdlib.h>
#define n 10

void bubbleSort(int *V);

int main() {
    int *V = (int*)malloc(n * sizeof(int));

    //Preenchendo o vetor
    printf("Digite valores para o vetor: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &V[i]);
    }

    //chamando a função para ordenar o vetor
    bubbleSort(V);

    //Imprimindo o vetor na tela
    for(int i = 0; i < n; i++){
        printf("[%d]", V[i]);
    }

    free(V);
    return 0;
}

//função de ordernação bubble sort de forma decrescente
void bubbleSort(int *V){
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

