//Exercicio EP02 - programa sequencial e tempo de execução - calculo da tangente

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

//Funções utilizada para os calculos
double sen_x(double x, int n);
double cos_x(double x, int n);
double fatorial(double valor);
double potencia(double x, int n);

int main(void){
    double sen, cos, tan, x; //Variaveis para armazenar o seno, cosseno, tangente e o valor em rad a ser passado
    int n = 15; //Numero para a precisão dos calculos do seno e cosseno
    double tempo; //Variavel que vai receber o resultado do tempo de execução
    time_t ini, fim; //Variavel que recebe o valor do tempo atual em que se encontra o programa
    
    //Entrada do valor em rad
    printf("Digite um valor: ");
    scanf("%lf", &x);

    ini = clock(); //Inicio da contagem de tempo
  
    sen = sen_x(x, n); //Calculando o sen do valor digitado
    cos = cos_x(x, n); //Calculando o cos do valor digitado
    tan = sen / cos; // Calculando a tangente

    fim = clock(); // fim da contagem de tempo
    tempo = (double) (fim - ini) * 1000 / CLOCKS_PER_SEC; //Resultado do tempo de execução

    //Imprimi na tela os resultados
    printf("sen(%.2lf) = %.8lf\n", x, sen);
    printf("cos(%.2lf) = %.8lf\n", x, cos);
    printf("tan(%.2lf) = %.8lf\n", x, tan);
    printf("Tempo de execução: %.5lf\n", tempo);
    return 0;   
}

//Função do calculo do sen
double sen_x(double x, int n){
    double resultado = 0;

    //Formula geral para o calculo do sen
    for(int i = 0; i < n; i++){
        resultado += potencia(-1, i) * potencia(x, 2*i + 1)/fatorial(2*i+1);
    }
    return resultado;   
}

//Função do calculo do cos
double cos_x(double x, int n){
    double resultado = 0;

    //Formula geral para o calculo do cos
    for(int i = 0; i < n; i++){
        resultado += potencia(-1, i) * potencia(x, 2*i)/fatorial(2*i);
    }
    return resultado;
}

//Função que calcula a potência
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

//Função que calcula o fatorial de um numero
double fatorial(double valor){
    double resultado = 1;
    for(int i = 1; i <= valor; i++){
            resultado *= i;
    }
    return resultado;
}





