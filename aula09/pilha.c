#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void inicializa(PILHA *pilha)
{
    pilha->topo = malloc(sizeof(CELULA));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
}
int vazia(PILHA *pilha)
{
    return(pilha->topo == pilha->fundo);
}
void empilha(ITEM x,PILHA *pilha)
{
    CELULA *aux;

        aux = malloc(sizeof(CELULA));
        aux->prox = pilha->topo;
        pilha->topo->item = x;
        pilha->topo = aux;
}
void esvazia(PILHA *pilha)
{
    CELULA *aux;
    CELULA *aux2;

    aux2 = pilha->topo;
    while(aux2->prox != NULL){
        aux = pilha->topo->prox;
        pilha->topo->prox = aux->prox;
        free(aux);
    }
}
void imprimir(PILHA *pilha)
{
    CELULA *aux;

    aux = pilha->topo->prox;
    while(aux != NULL){
        printf("\n %d", aux->item.chave);
        aux = aux->prox;
    }
    getchar();
}
void opera(char c, PILHA *pilha){
    CELULA *aux;

    aux = pilha->topo->prox;

    if(c == '+'){
        aux->prox->item.chave = aux->prox->item.chave + aux->item.chave;
        desempilha(pilha,aux);
    }
    if(c == '*'){
        aux->prox->item.chave = aux->prox->item.chave * aux->item.chave;
        desempilha(pilha,aux);
    }
    if(c == '/'){
        aux->prox->item.chave = aux->prox->item.chave / aux->item.chave;
        desempilha(pilha,aux);
    }
    if(c == '-'){
        aux->prox->item.chave = aux->prox->item.chave - aux->item.chave;
        desempilha(pilha,aux);
    }
}
void desempilha(PILHA *pilha, ITEM *x)
{
     CELULA *aux;

    if(vazia(pilha))
        printf("Erro: pilha vazia!!!");
    else
    {
        aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        *x = pilha->topo->item;
        free(aux);
    }
}
void adiciona(char op, PILHA *pilha){
    int i;
    i = op - '0';
    if(pilha->topo->prox->item.chave == 0)
        pilha->topo->prox->item.chave = i;
    else if(pilha->topo->prox->item.chave > 0)
        pilha->topo->prox->item.chave = (pilha->topo->prox->item.chave * 10) + i;
}
