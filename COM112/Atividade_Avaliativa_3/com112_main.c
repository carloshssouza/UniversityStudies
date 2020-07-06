#include <stdio.h>
#include <stdlib.h>
#include "com112_hash.h"
#define n 5
//link para repl it https://repl.it/join/kxssywhq-carloshenriqu42

//Função do menu
int menu();

int main() {
    //Tabela hash
    Hash *ha;

    //Struct de aluno onde estão os dados que vão ser lidos
    struct aluno al, alu[n];

    //variaveis para controle e leitura de dados
    int op, x, num, cont = 0, criado = 0;

    //Do-while para repetir a função menu
    do{
        op = menu();

        //Usando switch-case para a escolha das opções
        switch(op){
            //caso 1 é para a criação da tabela hash
            case 1:
                //se a variavel criado for igual a 0, nenhuma tabela foi criada ainda, entao podendo ser criada
                //se não, é porque já foi criada uma tabela
                if(criado == 0){
                    ha = criaHash(1427);
                    printf("Criado com sucesso\n");
                    criado++;
                } else
                    printf("Tabela ja criada\n");

                break;

             //case 2 serve para liberar a tabela, se ela foi criada
             //se não foi criada, não libera
            case 2:
                if(criado == 1){
                    liberaHash(ha);
                    printf("Liberado com sucesso\n");
                    criado--;
                }
                else
                    printf("Nao foi possivel liberar, tabela nao criada\n");

                break;

             //case 3 serve para inserir elemento da tabela, colocando os dados do aluno
            case 3:
                if(cont < n && criado == 1){
                    printf("Digite o numero da matricula: ");
                    scanf("%d", &alu[cont].matricula);
                    getchar();
                    printf("Digite o nome: ");
                    fgets(alu[cont].nome, 30, stdin);
                    printf("Digite a nota 1: ");
                    scanf("%f", &alu[cont].n1);
                    printf("Digite a nota 2: ");
                    scanf("%f", &alu[cont].n2);
                    x = insereHash_SemColisao(ha, alu[cont]);
                    if(x){
                        printf("Inserido com sucesso\n\n");
                        cont++;
                    }
                    else{
                        printf("Nao foi possivel inserir\n");
                    }
                }
                else
                    printf("Nao foi possivel inserir vetor cheio ou tabela nao criada\n");

                break;

             //case 4 serve para consultar um aluno na tabela, pelo numero de matricula, devolvendo todos os dados
             //só será consultado, se a tabela existir.
            case 4:
                if(criado == 1){
                    printf("Digite o numero da matricula: ");
                    scanf("%d", &num);
                    x = buscaHash_SemColisao(ha, num, &al);
                    if(x){
                        printf("\nNome: %s", al.nome);
                        printf("Matricula: %d\n", al.matricula);
                        printf("Nota 1: %.2f\n", al.n1);
                        printf("Nota 2: %.2f\n\n", al.n2);
                    }else
                        printf("Nao encontrado\n");
                }
                else
                    printf("Nao foi possivel consultar, tabela nao criada\n");

                break;
        }

    }while(op < 5);
    return 0;
}

//Função de menu, que imprimir as opções
int menu(){
    int op;
    printf("1 - Cria tabela hash\n");
    printf("2 - Liberar tabela hash\n");
    printf("3 - Inserir elemento(sem colisao)\n");
    printf("4 - Consultar elemento(sem colisao)\n");
    printf("5 - Sair\n");
    scanf("%d", &op);
    return op;
}
