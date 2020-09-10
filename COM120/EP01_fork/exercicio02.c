//Exercício 2
/*Modifique o exercício 1 para que o processo pai espere o processo filho terminar de executar antes de começar a exibir a frase “Sou o processo pai” na tela. Para isso, você pode utilizar a função waidpid definida no cabeçalho #include <unistd.h>.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    // Usado na função de espera, onde o processo pai será executado somente depois de todos os processos filhos
    int statusFilho;
    //utilizando fork para criar um processo
    int pid=fork();

    //se o processo for diferente de 0, quer dizer que quem vai ser executado é o processo pai
    if(pid != 0){
        for(int i = 0; i < 30; i++){
            waitpid(pid, &statusFilho, 0);
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
