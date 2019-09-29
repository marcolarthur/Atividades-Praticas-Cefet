#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED


typedef struct{
    int chave;
}ITEM;
typedef struct tcelula{
    ITEM item;
    struct tcelula *prox;
}CELULA;
typedef struct{
    CELULA *topo;
    CELULA *fundo;
}PILHA;

void inicializa(PILHA *pilha);
int vazia(PILHA *pilha);
void empilha(ITEM x,PILHA *pilha);
void opera(char c, PILHA *pilha);
void esvazia(PILHA *pilha);
void desempilha (PILHA *pilha, ITEM *x);
void adiciona (char op, PILHA *pilha);

#endif // BIBLIOTECA_H_INCLUDED
