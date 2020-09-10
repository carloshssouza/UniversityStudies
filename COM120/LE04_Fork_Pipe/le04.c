//Lista Exercício 4 - Fork e pipe
/*Desenvolver um programa em C/C++ que cria dois processos filhos e troca mensagens entre eles.
Processo Pai: Recebe dois parâmetros na inicialização. O processo pai cria dois processos filhos e
envia o primeiro parâmetro para o filho 1 e o segundo para o filho 2 atravéz de mensagens (pipe).
Quando os processos filhos retornam os resultados, o pai então soma e apresenta o resultado final
na tela.

Processo Filho 1: Recebe como mensagem (pipe) um número e retorna o quadrado deste número,
também através de mensagem.

Processo Filho 2: Recebe como mensagem (pipe) um número e retorna o fatorial do mesmo,
também atravéz de mensagem.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <time.h>


int main(void){
    //File descriptors para os Pipes:
    
    int fd_x[2], fd_x1[2], fd_y[2], fd_y1[2];

    pid_t pid, pid2; //Variaveis para armazenar os pids

    //Criando todos os pipes
    if(pipe(fd_x) < 0 || pipe(fd_x1) < 0 || pipe(fd_y) < 0 || pipe(fd_y1)){
        perror("pipe");
        return -1;
    }

    //Criando o processo do primeiro filho
    if((pid = fork()) < 0){
        perror("fork");
        exit(1);
    }

    //Filho 1
    if(pid == 0){
        int x_recebido; //Variável que vai receber o valor enviado pelo processo pai
        int resultado; //Variável que vai receber o resultado da operação a ser realizada

        close(fd_x[1]); //Usado para a leitura, então fecha-se a entrada de escrita
        close(fd_x1[0]); //Usado para escrita, então fecha-se a leitura
        
        //Leitura do valor enviado pelo processo pai
        read(fd_x[0], &x_recebido, sizeof(x_recebido));
         printf("PROCESSO FILHO 1 - valor recebido: %d\n\n", x_recebido); 
        
        //É calculado o quadrado do valor recebido
        resultado = x_recebido * x_recebido;

        //Enviando esse resultado para o processo pai
        write(fd_x1[1], &resultado, sizeof(resultado) + 1);

    }

    else{
        //Criando o processo do segundo filho
        if((pid2 = fork()) < 0){
            perror("fork");
            exit(1);
        }

        //Filho2
        if(pid2 == 0){
            int y_recebido; //Variável que vai receber o valor enviado pelo processo pai
            int resultado = 1; //Viarável que vai o resultado da operação a ser realizada

            close(fd_y[1]); //Usado para a leitura, então fecha-se a entrada de escrita
            close(fd_y1[0]); //Usado para escrita, então fecha-se a leitura

            //Leitura do valor enviado pelo processo pai
            read(fd_y[0], &y_recebido, sizeof(y_recebido));
            printf("PROCESSO FILHO 2 - valor recebido: %d\n\n", y_recebido);

            //É calculado o fatorial do valor recebido
            for(int i = 1; i <= y_recebido; i++){
                resultado *= i;
            }
            
            //Enviando esse resultado para o processo pai
            write(fd_y1[1], &resultado, sizeof(resultado) + 1);
        }
        else{
            
            close(fd_x[0]); //Usado para escrita, então fecha-se a leitura desse pipe
            close(fd_y[0]); //Usado para escrita, então fecha-se a leitura desse pipe
            close(fd_x1[1]); //Usado para leitura, então fecha-se a escrita desse pipe
            close(fd_y1[1]); //Usado para leitura, então fecha-se a escrita desse pipe
         
            //Gerando numeros aleatórios de 1 a 10 para as variáveis
            srand(time(NULL));
            int x = rand() % 10 + 1, y = rand() % 10 + 1;

            int x_resultado, y_resultado; //Variáveis que recebem os resultados enviados pelos processos filho.
            int soma; //Variável que recebe a soma dos resultados enviados pelos processos filho

            write(fd_x[1], &x, sizeof(x) + 1); //Enviando um valor para o processo filho 1
            read(fd_x1[0], &x_resultado, sizeof(x_resultado)); //Recebendo o resultado enviado pelo processo filho 1
            
            write(fd_y[1], &y, sizeof(y) + 1); //Enviando um valor para o processo filho 2
            read(fd_y1[0], &y_resultado, sizeof(y_resultado)); //Recebendo o resultado enviado pelo processo filho 2

            soma = x_resultado + y_resultado; //Somando os resultados enviados
            printf("PROCESSO PAI\n");
            printf("Valor recebido do processo filho 1: %d\n", x_resultado);
            printf("Valor recebido do processo filho 2: %d\n", y_resultado);
            printf("A soma é: %d\n", soma);
        } 
    }
    return 0;
}




