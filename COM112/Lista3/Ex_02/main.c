#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 10

//Definindo funcionario com nome e salario
typedef struct funcionario{
    float salario;
    char nome[20];
}Funcionario;

//Função de ordenação Selection Sort para ordenar os salários em ordem decrescente
void selectionSortSalario(Funcionario *V);

//Função de ordenação Selection Sort para ordenar os nomes em ordem alfabética
void selectionSortNome(Funcionario *V);

int main() {
    //Alocando memoria para o vetor do tipo Funcionario
    Funcionario *V = (Funcionario*)malloc(n * sizeof(Funcionario));

    //Entrada dos dados do nome e salario dos funcionarios
    for(int i = 0; i < n; i++){

        printf("Digite o nome do funcionario [%d]: ", i+1);
        fgets(V[i].nome, 20, stdin);


        printf("Digite o salário do funcionario[%d]: ", i+1);
        scanf("%f", &V[i].salario);
        getchar();
    }

    //Chamando a função para ordernar o vetor, com os salários em ordem decrescente
    selectionSortSalario(V);

    //imprimindo os salarios ordenados em ordem decrescente
    printf("\nEm ordem decrescente dos salarios\n");
    for(int i = 0; i < n; i++){
        printf("[%.2f] - %s", V[i].salario, V[i].nome);
    }

    //Chamando a função para ordenar o vetor, com os nomes em ordem alfabética
    selectionSortNome(V);

    //Imprimindo os nomes em ordem alfabética
    printf("\nEm ordem alfabetica dos nomes\n");
    for(int i = 0; i < n; i++){
        printf("%s", V[i].nome);
    }

    free(V);
    return 0;
}

void selectionSortSalario(Funcionario *V){
    int menor;
    Funcionario troca;

    for(int i = 0; i < n-1; i++){
        menor = i;
        for(int j = i+1; j < n; j++){
            if(V[j].salario > V[menor].salario){
                menor = j;
            }
        }
        if(i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

void selectionSortNome(Funcionario *V){
    int menor;
    Funcionario troca;
    
    for(int i = 0; i < n-1; i++){
        menor = i;
        for(int j = i+1; j < n; j++){
            if(strcmp(V[j].nome, V[menor].nome) < 0){
                menor = j;
            }
        }
        if(i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}
