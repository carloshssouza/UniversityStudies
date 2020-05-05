#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com112_file.h"
#include "com112_sort.h"


//Função para apresentar o menu de opções
int menu();

//Função que imprimi na tela tempo de execução, nª de comparações e nº de movimentações
int relatorio(double tempo, int n_compara, int n_movimento, int *V2, int n);


int main() {
    //declarando variável para o calculo do tempo de execução em milissegundos
    clock_t c1, c2;

    //definindo a quantiadade de elementos
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    //Alocando memória para o vetor de entrada(V) e para o (V2) que vai receber os valores ordenados
    int *V = (int*)malloc(n * sizeof(int));
    int *V2 = (int*)malloc(n * sizeof(int));

    //op é a variável que recebe o valor da opção a ser escolhida, ok vai receber função relatório
    //n_compara é o número de comparações e n_movimento o número de movimento de elementos
    int op = 0, n_compara = 0, n_movimento = 0, ok = 0;

    //Usei marcadores para não poder usar o mesmo método de ordenação mais de uma vez
    //Já que os elementos de entradas são os mesmos, não faz sentido usar o mesmo método
    int marcador_B = 0, marcador_S = 0, marcador_I = 0;

    //variável que receberá o tempo de execução
    double tempo = 0;

    //preenchendo o vetor de entrada com valores aleatórios
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        V[i] = rand() % n + 1;
        printf("%d\n", V[i]);
    }

    //Criando o arquivo de entrada com112_entrada.txt onde ficará registrado os elementos do vetor
    fileEntrada(V, n);

    //Usando do while para repetir o print do menu e poder selecionar as opções
    do{
        //zerando as variáveis, para serem aproveitadas nos 3 métodos e não serem somadas errando o resultado.
        tempo = 0;
        n_compara = 0;
        n_movimento = 0;

        //op recebendo a função que mostra o menu e retorna um valor
        op = menu();

        //switch-case para efetuar o método escolhido
        //Os comentários do caso 1, servem de referência para os outros casos
        //Apenas as funções dos métodos de ordenação são diferentes, mas tem o mesmo objetivo.
        switch(op){

            case 1:
                //se o marcador for 0, entrará no if, se não for igual a 0, é porque já foi usado esse método
                if(marcador_B == 0) {
                    //fazendo a leitura do arquivo de entrada com112_entrada.txt e colocando em um vetor 2
                    fileLeitura(V2, n);

                    //c1 e c2 usados para calcular o tempo de execução do método de ordenação e chamando a função
                    c1 = clock();
                    bubbleSort(V2, &n_compara, &n_movimento, n);
                    c2 = clock();
                    tempo = (double) (c2 - c1) * 1000 / CLOCKS_PER_SEC;

                    //Passando o resultado para com112_relatorio.txt
                    fileBubble(tempo, n_compara, n_movimento);

                    //imprimindo na tela o resultado
                    ok = relatorio(tempo, n_compara, n_movimento, V2, n);

                    //somando no marcador, para não repetir o mesmo método de ordenação, já que daria o mesmo resultado
                    marcador_B++;
                } else{
                    printf("Elementos ja ordenados por Bubble Sort\n");
                }

                break;

            case 2:
                if(marcador_S == 0) {
                    fileLeitura(V2, n);
                    c1 = clock();
                    selectionSort(V2, &n_compara, &n_movimento, n);
                    c2 = clock();
                    tempo = (double) (c2 - c1) * 1000 / CLOCKS_PER_SEC;
                    fileSelection(tempo, n_compara, n_movimento);
                    ok = relatorio(tempo, n_compara, n_movimento, V2, n);
                    marcador_S++;
                } else{
                    printf("Elementos ja ordenados por Selection Sort\n");
                }

                break;

            case 3:
                if(marcador_I == 0) {
                    fileLeitura(V2, n);
                    c1 = clock();
                    insertionSort(V2, &n_compara, &n_movimento, n);
                    c2 = clock();
                    tempo = (double) (c2 - c1) * 1000 / CLOCKS_PER_SEC;
                    fileInsertion(tempo, n_compara, n_movimento);
                    ok = relatorio(tempo, n_compara, n_movimento, V2, n);
                    marcador_I++;
                } else{
                    printf("Elementos ja ordenados por Selection Sort\n");
                }


                break;


        }
    }while(op > 0 && op < 4);

    //Passando os elementos ordenados para com112_saida.txt
    fileSaida(V2, n);
    printf("Finalizando...\n");
    free(V);
    free(V2);

    return 0;
}

//Função menu de opções, retornando o valor da opção
int menu(){
    int op;
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Sair\n");
    scanf("%d", &op);

    return op;
}

//Função para imprimir
int relatorio(double tempo, int n_compara, int n_movimento, int *V2, int n){
    printf("\n1. Tempo de execucao: %lf\n", tempo);
    printf("2. Numero de comparacoes: %d\n", n_compara);
    printf("3. Numero de movimentacoes entre elementos do vetor: %d\n\n", n_movimento);
    for(int i = 0; i < n; i++){
        printf("%d ", V2[i]);
    }
    printf("\n\n");

    return 1;
}