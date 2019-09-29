#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    char op;

    PILHA pilha;

    ITEM x;

    inicializa(&pilha);

    printf("\t\t CALCULADORA POLONESA \n\n  pressione 'i' para imprimir o resultado\n  pressione 'x' para sair \n\n");

    do{
        scanf("%s", &op);
        if(op != 'x'){
            if(op == 'e'){
                x.chave = 0;
                empilha(x, &pilha);
            }
            else if(op == '+' || op == '-' || op == '*' || op == '/'){
                opera(op,&pilha);
            }
            else if(op == 'c'){
                esvazia(&pilha);
            }
            else if(op == 'i'){
                imprimir(&pilha);
            }
            else {
                adiciona(op,&pilha);
            }
        }
    }while(op != 'x');
    getch();
}
