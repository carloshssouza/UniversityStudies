#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 10

//definindo produto
typedef struct produto{
    int codigo;
    char descricao[20];
    float preco;
}Produto;

//função de ordenação Insertion Sort, para ordenar em ordem alfabética os produtos
void insertionSort(Produto *V);

//função para busca sequencial, usando o código do produto, retornando a quantidade de comparações
int buscaSequencial(Produto *V, int cod);

int main() {
    //aloacando memoria para o vetor do tipo Produto
    Produto *V = (Produto*)malloc(n * sizeof(Produto));

    //variavel cod para entrada do codigo digitado
    //variavel busca para receber a função de busca
    int cod, busca;

    //Entrada dos dados do vetor
    for(int i = 0; i < n; i++){

        //gerando valor de forma automatica para codigo e printando
        V[i].codigo = i+1000;
        printf("\nCodigo %d produto[%d]\n", V[i].codigo, i+1);

        //Nome para a descrição do produto
        printf("Descrição Produto[%d]: ", i+1);
        fgets(V[i].descricao, 20, stdin);

        //Valor para o preço do produto
        printf("Preco Produto[%d]: ", i+1);
        scanf("%f", &V[i].preco);
        getchar();
    }

    //Chamando a função para ordenar o vetor em ordem alfabética, de acordo com a descrição
    printf("\n\nOrdenando...\n\n");
    insertionSort(V);

    //Printando os produtos em ordem alfabética, mostrando a descrição, codigo e preço
    for(int i = 0; i < n; i++){
        printf("Descricao : %s ", V[i].descricao);
        printf("Codigo: %d\n", V[i].codigo);
        printf("Preco: %.2f\n\n", V[i].preco);
    }
    printf("=====================================\n");

    //Fazendo a busca pelo código e retornando a quantidade de comparações e o produto
    printf("\nDigite o codigo a ser buscado: ");
    scanf("%d", &cod);
    busca = buscaSequencial(V, cod);
    if(busca != -1){
        printf("%d de comparacoes para achar o produto: %s", busca, V[busca-1].descricao);
    }
    else{
        printf("Produto nao encontrado");
    }

    free(V);
    return 0;
}

void insertionSort(Produto *V){
    Produto aux;
    int j;
    for(int i = 0; i < n; i++){
        aux = V[i];
        for(j = i; (j > 0) && (strcmp(aux.descricao, V[j-1].descricao) < 0); j--){
            V[j] = V[j-1];
        }
        V[j] = aux;
    }
}

int buscaSequencial(Produto *V, int cod){
   for(int i = 0; i < n; i++){
       if(cod == V[i].codigo){
           return i+1;
       }
   }
   return -1;
}