#include <stdlib.h>
#include <stdio.h>
#include "com112_arvoreAVL.h"

//Estrutura em que o No da arvore tem
struct NO{
    int elemento;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

//Função que cria a arvore
ArvoreAVL *criar_arvore(){
    ArvoreAVL *raiz = (ArvoreAVL*) malloc(sizeof(ArvoreAVL));
    if(raiz != NULL){
        *raiz = NULL;
    }

    return raiz;
}

//Funções pra liberar(destruir) a arvore
void liberar_no(struct NO* no){
    if(no == NULL)
        return;
    liberar_no(no->esq);
    liberar_no(no->dir);
    free(no);
    no = NULL;
}
void liberar_arvore(ArvoreAVL *raiz){
    if(raiz == NULL)
        return;
    liberar_no(*raiz);
    free(raiz);
}

//arvore vazia
int arvore_vazia(ArvoreAVL *raiz){
    if(raiz == NULL) return 1;
    if(*raiz == NULL) return 1;

    return 0;
}

//Funções auxiliares da arvore avl
int alt_NO(struct NO* no){
    if(no == NULL) return -1;

    else return no->alt;
}

int fBalanceamento_NO(struct NO* no){

    return abs(alt_NO(no->esq) - alt_NO(no->dir));
}

int maior(int x, int y){
    if(x > y) return x;

    else return y;
}

void RotacaoLL(ArvoreAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->esq), (*raiz)->alt) + 1;

    *raiz = no;
}

void RotacaoRR(ArvoreAVL *raiz){
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->dir), (*raiz)->alt) + 1;

    *raiz = no;
}

void RotacaoRL(ArvoreAVL *raiz){
    RotacaoLL(&(*raiz)->dir);
    RotacaoRR(raiz);
}


void RotacaoLR(ArvoreAVL *raiz){
    RotacaoRR(&(*raiz)->esq);
    RotacaoLL(raiz);
}

//Função pra calcular a altura da arvore
int altura_arvore(ArvoreAVL *raiz){
    if(raiz == NULL) return 0;
    if (*raiz == NULL) return 0;

    int altura_esq = altura_arvore(&((*raiz)->esq));
    int altura_dir = altura_arvore(&((*raiz)->dir));
    if(altura_esq > altura_dir) return(altura_esq + 1);
    else return (altura_dir + 1);

}

//Função que calcula o total de elementos na arvore
int total_no_arvore(ArvoreAVL *raiz){
    if(raiz == NULL) return 0;
    if (*raiz == NULL) return 0;

    int altura_esq = total_no_arvore(&((*raiz)->esq));
    int altura_dir = total_no_arvore(&((*raiz)->dir));

    return(altura_esq + altura_dir + 1);
}

//Funções que printar em pre-ordem, em ordem e pos-ordem
void pre_ordem(ArvoreAVL *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->elemento);
        pre_ordem(&((*raiz)->esq));
        pre_ordem(&((*raiz)->dir));
    }
}

void em_ordem(ArvoreAVL *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        em_ordem(&((*raiz)->esq));
        printf("%d\n", (*raiz)->elemento);
        em_ordem(&((*raiz)->dir));
    }
}

void pos_ordem(ArvoreAVL *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        pos_ordem(&((*raiz)->esq));
        pos_ordem(&((*raiz)->dir));
        printf("%d\n", (*raiz)->elemento);
    }
}

//Função para inserir elemento da na arvore
int add_arvore(ArvoreAVL *raiz, int valor){
    int result;

    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL) return 0;

        novo->elemento = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    struct NO* atual = *raiz;
    if(valor < atual->elemento){
        if((result=add_arvore(&(atual->esq), valor)) == 1){
            if(fBalanceamento_NO(atual) >= 2){
                if(valor < (*raiz)->esq->elemento){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }

        }
    }
    else{
        if(valor > atual->elemento){
            if((result = add_arvore(&(atual->dir), valor)) == 1){
                if(fBalanceamento_NO(atual) >= 2){
                    if((*raiz)->dir->elemento < valor){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Elemento duplicado\n");
            return 0;
        }
    }
    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;
    return result;
}

//Função para remover elementos da arvore
struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}
int remove_arvore(ArvoreAVL *raiz, int valor){
    if(*raiz == NULL){
        printf("Elemento nao existe!!\n");
        return 0;
    }
    int result;
    if(valor < (*raiz)->elemento){
        if((result=remove_arvore(&(*raiz)->esq, valor)) == 1){
            if(fBalanceamento_NO(*raiz) >= 2){
                if(alt_NO((*raiz)->dir->esq) <= alt_NO((*raiz)->dir->dir)){
                    RotacaoRR(raiz);
                }else{
                    RotacaoRL(raiz);
                }
            }
        }
    }
    if((*raiz)->elemento < valor){
        if((result=remove_arvore(&(*raiz)->dir, valor)) == 1){
            if(fBalanceamento_NO(*raiz) >= 2){
                if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq)){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }
    if((*raiz)->elemento == valor) {
        if (((*raiz)->esq == NULL || (*raiz)->dir == NULL)) {
            struct NO *oldNo = (*raiz);
            if ((*raiz)->esq != NULL) *raiz = (*raiz)->esq;

            else *raiz = (*raiz)->dir;
            free(oldNo);
        } else {
            struct NO *temp = procuraMenor((*raiz)->dir);
            (*raiz)->elemento = temp->elemento;
            remove_arvore(&(*raiz)->dir, (*raiz)->elemento);
            if (fBalanceamento_NO(*raiz) >= 2) {
               if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq)){
                   RotacaoLL(raiz);
               }else{
                   RotacaoLR(raiz);
               }
            }
        }
        return 1;
    }
    return result;


}

//Função para consultar um elemento na arvore
int consulta_arvore(ArvoreAVL *raiz, int valor){
    if(raiz == NULL) return 0;

    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->elemento)
            return 1;

        if(valor > atual->elemento)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}




