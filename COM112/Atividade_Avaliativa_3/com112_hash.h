//struct do aluno com os dados
struct aluno{
    int matricula;
    char nome[30];
    float n1, n2;
};

//funções que serão usadas na tabela hash
typedef struct hash Hash;
Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash *ha);
int  insereHash_SemColisao(Hash *ha, struct aluno al);
int buscaHash_SemColisao(Hash *ha, int mat, struct aluno *al);
