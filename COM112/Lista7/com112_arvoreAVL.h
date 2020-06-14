//Arvore
typedef struct NO* ArvoreAVL;

//Função para criar a arvore e destruir a arvore
ArvoreAVL *criar_arvore();
void liberar_arvore(ArvoreAVL *raiz);

//Funções para verifica se a arvore está vazia, calcular altura e o total de elementos na arvore
int arvore_vazia(ArvoreAVL *raiz);
int altura_arvore(ArvoreAVL *raiz);
int total_no_arvore(ArvoreAVL *raiz);

//Funções para printar em pre-ordem, em ordem e pos-ordem
void pre_ordem(ArvoreAVL *raiz);
void em_ordem(ArvoreAVL *raiz);
void pos_ordem(ArvoreAVL *raiz);

//Funções para inserir, remover e consultar elementos da arvore
int add_arvore(ArvoreAVL *raiz, int valor);
int remove_arvore(ArvoreAVL *raiz, int valor);
int consulta_arvore(ArvoreAVL *raiz, int valor);