#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct ITEM{
    int chave;
}ITEM;

typedef struct CELULA{
    ITEM item;
    struct CELULA *prox;
}CELULA;

typedef struct PILHA{
    CELULA *topo;
    CELULA *fundo;
}PILHA;

void inicializa(PILHA *pilha){
    pilha->topo = (CELULA *) malloc(sizeof(CELULA));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
}

void empilha(ITEM x, PILHA *pilha){
    CELULA *aux;
    aux = (CELULA *) malloc(sizeof(CELULA));
    aux->prox = pilha->topo;
    pilha->topo->item = x;
    pilha->topo = aux;
}

void desempilha(PILHA *pilha, ITEM *x){
    CELULA *aux;
    if (vazia(pilha))
        printf("Erro: pilha vazia!!!\n");
    else{
        aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        *x = pilha->topo->item;
        free(aux);
    }
}


int vazia(PILHA *pilha){
    return(pilha->topo == pilha->fundo);
}

void imprimePilha(PILHA *pilha){
    CELULA *aux = pilha->topo->prox;
    while(aux!=NULL){
        printf("%d\n", aux->item.chave);
        aux = aux->prox;
    }
}

void copia(PILHA *p1, PILHA *p2){
    PILHA pAux;
    ITEM x;

    inicializa(&pAux);
    while (!vazia(p1)){
        desempilha(p1, &x);
        empilha(x, &pAux);
    }
    while(!vazia(&pAux)){
        desempilha(&pAux, &x);
        empilha(x, p1);
        empilha(x, p2);
    }
}

void acessaTopo (PILHA *p, ITEM *x){
    *x = p->topo->prox->item;
}

main() {
    setlocale(LC_ALL, "");
    PILHA pilha;
    inicializa(&pilha);
    int p;
    ITEM x;
    PILHA p2;
    while(p!=0){
        printf("*** MENU ***\n1-Empilhar\n2-Desempilhar\n3-Vazia\n4-Imprimir\n5-Copiar\n6-Acessar topo\n0-Sair\n");
        scanf("%d", &p);
        switch(p){
            case 1:
                printf("Insira o que deseja empilhar: ");
                scanf("%d", &x.chave);
                empilha(x, &pilha);
                break;
            case 2:
                if(vazia(&pilha)){
                    printf("Pilha vazia.\n");
                    break;
                }
                desempilha(&pilha, &x);
                printf("Desempilhado: %d\n", x.chave);
                break;
            case 3:
                if(vazia(&pilha)){
                    printf("Pilha vazia.\n");
                }
                else
                    printf("Pilha não vazia.");
                break;
            case 4:
                if(vazia(&pilha)){
                    printf("Pilha vazia.");
                }
                else {
                    printf("Pilha: ");
                    imprimePilha(&pilha);
                }
                break;
            case 5:
                inicializa(&p2);
                if(vazia(&pilha))
                    printf("Pilha vazia.\n");
                else{
                    copia(&pilha, &p2);
                    printf("Pilha 2: ");
                    imprimePilha(&p2);
                }
                break;
            case 6:
                if(vazia(&pilha))
                    printf("Pilha vazia.\n");
                else{
                    acessaTopo(&pilha, &x);
                    printf("Topo: %d\n", x.chave);
                }
            case 0: break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }
    return 0;
}
