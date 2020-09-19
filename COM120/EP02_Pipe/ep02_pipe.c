//Exercicio EP02 - pipe e tempo de execução - calculo da tangente

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

double fatorial(double x); //Função para o calculo do fatorial
double potencia(double x, int n); //Função para o calculo da potencia

int main(void){
    //File descriptors para os Pipes:
    int fd1_pid[2], fd2_pid[2], fd1_pid2[2], fd2_pid2[2]; 

    pid_t pid, pid2; //Variaveis para armazenar os pids

    clock_t ini, fim; //Variavel que recebe o valor do tempo atual em que se encontra o programa
    double tempo; //Variavel que vai receber o resultado do tempo de execução

    //Criando todos os pipes
    if(pipe(fd1_pid) < 0 || pipe(fd2_pid) < 0 || pipe(fd1_pid2) < 0 || pipe(fd2_pid2)){
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
        double x_recebido; //Variável que vai receber o valor enviado pelo processo pai
        double resultado = 0; //Variável que vai receber o resultado da operação a ser realizada
        int n = 15; //Numero para a precisão do calculo do sen

        close(fd1_pid[1]); //Usado para a leitura, então fecha-se a entrada de escrita
        close(fd2_pid[0]); //Usado para escrita, então fecha-se a leitura
        
        //Leitura do valor enviado pelo processo pai
        read(fd1_pid[0], &x_recebido, sizeof(x_recebido));
        
        //É calculado o sen do valor recebido
        for(int i = 0; i < n; i++){
            resultado += potencia(-1, i) * potencia(x_recebido, 2*i + 1)/fatorial(2*i+1);
        }
        write(fd2_pid[1], &resultado, sizeof(resultado)); //Enviando o resultado obtido para o processo pai
    }

    else{
        //Criando o processo do segundo filho
        if((pid2 = fork()) < 0){
            perror("fork");
            exit(1);
        }

        //Filho2
        if(pid2 == 0){
            int n = 15; //Numero para a precisão do calculo do cos
            double x_recebido; //Variável que vai receber o valor enviado pelo processo pai
            double resultado = 0; //Viarável que vai o resultado da operação a ser realizada

            close(fd1_pid2[1]); //Usado para a leitura, então fecha-se a entrada de escrita
            close(fd2_pid2[0]); //Usado para escrita, então fecha-se a leitura

            //Leitura do valor enviado pelo processo pai
            read(fd1_pid2[0], &x_recebido, sizeof(x_recebido));
           
            //É calculado cos do valor recebido
            
            for(int i = 0; i < n; i++){
                 resultado += potencia(-1, i) * potencia(x_recebido, 2*i)/fatorial(2*i);
            }
           
            write(fd2_pid2[1], &resultado, sizeof(resultado)); //Enviando o resultado obtido para o processo pai
        }
        else{
            close(fd1_pid[0]); //Usado para escrita, então fecha-se a leitura desse pipe
            close(fd1_pid2[0]); //Usado para escrita, então fecha-se a leitura desse pipe
            close(fd2_pid[1]); //Usado para leitura, então fecha-se a escrita desse pipe
            close(fd2_pid2[1]); //Usado para leitura, então fecha-se a escrita desse pipe

            double x, cos, sen, tan; //Variaveis para armazenar o valor em rad a ser digitado, seno, cosseno e tangente
            
            //Entrada do valor em rad
            printf("Digite o valor: ");
            scanf("%lf", &x);

            ini = clock(); //Inicio da contagem de tempo
        
            write(fd1_pid[1], &x, sizeof(x) + 1); //Enviando um valor para o processo filho 1
            read(fd2_pid[0], &sen, sizeof(sen)); //Recebendo o valor do resultado enviado pelo filho 1
            
            
            write(fd1_pid2[1], &x, sizeof(x) + 1); //Enviando um valor para o processo filho 2
            read(fd2_pid2[0], &cos, sizeof(cos)); //Recebendo o valor do resultado enviado pelo processo filho 2
            
            tan = sen/cos; //Calculado o tangente

            fim = clock(); //Fim da contagem de tempo
            tempo = (double) (fim - ini) * 1000 / CLOCKS_PER_SEC; // Resultado do tempo de execução

            //Imprimi na tela os resultados
            printf("sen(%.2lf) = %.8lf\n", x, sen);
            printf("cos(%.2lf) = %.8lf\n", x, cos);
            printf("tan(%.2lf) = %.8lf\n", x, tan);
            printf("Tempo de execução: %.5lf\n", tempo);
        } 
    }
    return 0;
}

//calcula o fatorial de um numero
double fatorial(double x){
    double resultado = 1;
    for(int i = 1; i <= x; i++){
            resultado *= i;
    }
    return resultado;
}

//Calcula a potencia de um numero
double potencia(double x, int n){
    double resultado = x;
    if(n == 0){
        return 1;
    }

    for(int i = 1; i < n; i++){
        resultado *= x;
    }
    return resultado;
}



