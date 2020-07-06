#include <stdlib.h>
#include <string.h>
#include "com112_hash.h"


struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

//cria tabela hash
Hash * criaHash(int TABLE_SIZE){
    Hash* ha=(Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**)malloc(TABLE_SIZE * sizeof(struct aluno*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(int i = 0; i < ha->TABLE_SIZE; i++){
            ha->itens[i] = NULL;
        }


    }
    return ha;
}

//libera a tabela hash
void liberaHash(Hash *ha){
    if(ha != NULL){
        for(int i = 0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL) free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

//metodo de divisao
int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

//insere na tabela hash, atraves do metodo de divisal, sem tratamento de colisão
int insereHash_SemColisao(Hash *ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE) return 0;

    int chave = al.matricula;

    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno* novo;
    novo = (struct aluno*)malloc(sizeof(struct aluno));
    if(novo == NULL) return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

//busca na tabela hash, pelo metodo de divisal, sem tratamento de colisão
int buscaHash_SemColisao(Hash* ha, int mat, struct aluno* al){
    if(ha == NULL)
        return 0;

    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL)
        return 0;
    *al = *(ha->itens[pos]);
    return 1;
}
