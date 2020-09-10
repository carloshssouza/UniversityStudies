//Exercício 1
/*Crie um programa em C que cria um processo filho através do fork(). O processo original deve exibir na tela a frase “Sou o processo pai” 30 vezes, enquanto o processo filho deve exibir a frase “Sou o processo filho” 1000 vezes na tela.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    //utilizando fork para criar um processo
    int pid=fork();

    //se o processo for diferente de 0, quer dizer que quem vai ser executado é o processo pai
    if(pid != 0){
        for(int i = 0; i < 30; i++){
            printf("%d - Sou o processo pai\n", i);
            sleep(2);
        }

        //se for igual a 0, é criado um processo filho e é executado
    }else{
        for (int i = 0; i < 1000; ++i) {
            printf("%d - Sou o processo filho\n", i);
            sleep(1);
        }
    }
    return 0;
}
