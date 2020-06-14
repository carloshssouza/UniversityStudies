#include <stdio.h>
#include "com112_arvoreAVL.h"

//Função que apresenta o menu
int menu();

int main() {

    //Declarando a raiz da arvore e as variaveis que serão usadas
    ArvoreAVL *raiz;
    int op = 0;
    int ok = 0, valor, altura, total;

    //Usando Do-While para fazer um loop do menu de opções
    do{

        //Recebendo o valor do retorno da função menu, na variavel op
        op = menu();

        //Usando switch-case para realizar as funções da arvore, de acordo com o numero da opção
        switch(op){

            //Criar arvore
            case 1:
                raiz = criar_arvore();
                if(raiz != NULL)
                    printf("Arvore criada com sucesso\n");
                else
                    printf("Arvore nao criada\n");
                break;

            //Liberar arvore
            case 2:
                if(raiz != NULL){
                    liberar_arvore(raiz);
                    printf("Arvore Destruida\n");
                }
                else printf("Arvore nao criada\n");
                break;

            //Inserir elemento
            case 3:
                if(raiz == NULL) printf("Arvore nao criada\n");
                else{
                    printf("Digite o valor: \n");
                    scanf("%d", &valor);
                    ok = add_arvore(raiz, valor);
                    if(ok) printf("Inserido com sucesso\n");
                    else printf("Nao inserido\n");
                }
                break;

            //Remover elemento
            case 4:
                if(raiz == NULL) printf("Arvore nao criada\n");
                else{
                    printf("Digite o valor a ser removido: \n");
                    scanf("%d", &valor);
                    ok = remove_arvore(raiz, valor);
                    if(ok) printf("Removido com sucesso\n");
                    else printf("Nao removido\n");
                }
                break;

            //Consultar elemento
            case 5:
                if(raiz == NULL) printf("Arvore nao criada");
                else{
                    printf("Digite o valor a ser consultado\n");
                    scanf("%d", &valor);
                    ok = consulta_arvore(raiz, valor);
                    if(ok)printf("O valor %d foi encontrado\n", valor);
                    else printf("Valor nao encontrado");
                }
                break;

            //Imprimir percurso pre-ordem
            case 6:
                if(raiz == NULL) printf("Arvore nao criada");
                else{
                    ok = arvore_vazia(raiz);
                    if(ok) printf("Arvore vazia\n");
                    else pre_ordem(raiz);
                }
                break;

            //Imprimir percurso em ordem
            case 7:
                if(raiz == NULL) printf("Arvore nao criada");
                else{
                    ok = arvore_vazia(raiz);
                    if(ok) printf("Arvore vazia\n");
                    else em_ordem(raiz);
                }
                break;

            //Imprimir percurso em pos-ordem
            case 8:
                if(raiz == NULL) printf("Arvore nao criada");
                else{
                    ok = arvore_vazia(raiz);
                    if(ok) printf("Arvore vazia\n");
                    else pos_ordem(raiz);
                }
                break;

            //Altura da arvore
            case 9:
                if(raiz == NULL) printf("Arvore nao criada");
                else{
                    altura = altura_arvore(raiz);
                    if(altura > 0) printf("Altura: %d\n", altura);
                    else printf("Nao foi possivel calcular a altura!!\n");
                }
                break;

            //Total de elementos
            case 10:
                if(raiz == NULL) printf("Arvore nao criada");
                else{
                    total = total_no_arvore(raiz);
                    if(total > 0) printf("Total de elementos: %d\n", total);
                    else printf("Nao foi possivel calcular o total de elementos!!\n");
                }
                break;
        }
    }while(op < 11);

    printf("Finalizando...");
    return 0;
}

int menu(){
    int op;
    printf("1 - Criar arvore\n");
    printf("2 - Liberar arvore\n");
    printf("3 - Inserir elemento\n");
    printf("4 - Remover elemento\n");
    printf("5 - Consultar elemento\n");
    printf("6 - Imprimir percurso pre-ordem\n");
    printf("7 - Imprimir percurso em ordem\n");
    printf("8 - Imprimir percurso pos-ordem\n");
    printf("9 - Altura da arvore\n");
    printf("10 - Total de elementos\n");
    printf("11 - Sair\n");

    //Se digitar a opção errada, entrará no laço, até digitar uma das opções
    do{
        printf("Digite a opcao de 1 a 11\n");
        scanf("%d", &op);
    }while(op < 0 || op > 11);
    return op;
}