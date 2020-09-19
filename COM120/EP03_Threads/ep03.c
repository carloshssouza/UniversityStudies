//EP03 - Threads - calculando média, maior número e menor número

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

//Variáveis globais, usadas nos threads;
int SIZE; //Tamanho da lista de números
float valorMedia; //Variável que vai receber o resultado da média dos números da lista
int valorMaior; //Variável que vai receber o maior número da lista
int valorMenor; //Variável que vai receber o menor número da lista

void * media(void * arg); //Função do Thread 1
void * maior(void * arg); //Função do Thread 2
void * menor(void * arg); //Função do Thread 3

int main(int argc, char **argv){
    int *lista; //Lista de números(vetor)
    SIZE = atoi(argv[1]); //Recebe um numero por linha de comando, que é convertido de string para int

    pthread_t t1, t2, t3; //Identificadores dos threads

    lista = (int*)malloc(SIZE * sizeof(int)); //Alocando espaço da lista de números(vetor)

    //Preenchendo a lista(vetor) com números aleatórios de 1 a 20
    printf("\nNúmeros: \n");
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        lista[i] = 1 + rand() % 20;
        printf("%d ", lista[i]);
    }

    //Criando os threads para a execução das funções passadas para cada um e passando a lista(vetor) de números
    pthread_create(&t1, NULL, media, (void *)(lista));
    pthread_create(&t2, NULL, maior, (void *)(lista));
    pthread_create(&t3, NULL, menor, (void *)(lista));

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Á media dos numeros da lista: %.2f\n\n", valorMedia);
    printf("O maior numero da lista: %d\n\n", valorMaior);
    printf("O menor numero da lista: %d\n\n", valorMenor);

    free(lista);
    return EXIT_SUCCESS;
}

//Calculando a média
void * media(void * arg){
    printf("\n\nThread 1 executando...\n");
    int *lista_m = (int*)(arg);
    float soma = 0;
    for(int i = 0; i < SIZE; i++){
        soma+= lista_m[i];
    }
    valorMedia = soma/SIZE;
    pthread_exit(0);
}

//Procurando o maior valor
void * maior(void * arg){
    printf("Thread 2 executando...\n");
    int *lista_m = (int*)(arg); 
    int aux = 0;

    for(int i = 0; i < SIZE; i++){
        if(lista_m[i] > aux){
            aux = lista_m[i];
        }
    }
    valorMaior = aux;
    pthread_exit(0);
}

//Procurando o menor valor
void * menor(void * arg){
    printf("Thread 3 executando..\n\n");
    int *lista_m = (int*)(arg);
    int aux = lista_m[0];
    
    for(int i = 0; i < SIZE; i++){
        if(lista_m[i] < aux){
            aux = lista_m[i];
        }
    }
    valorMenor = aux;
    pthread_exit(0);
}



