
#include <bits/stdc++.h>
#include <locale.h>

struct PILHA
{

    int topo;
    int capa;
    float *ptrElemento;

};

void CriaPilha( struct PILHA *p, int c )
{

    p->topo = -1;
    p->capa = c;
    p->ptrElemento = (float*) malloc (c * sizeof(float));

}
int PilhaDescarregada ( struct PILHA *p )
{
    

    if( p-> topo == -1 )

        return 1;

    else

        return 0;

}

int PilhaCheia ( struct PILHA *p )
{

    if (p->topo == p->capa - 1)

        return 1;

    else

        return 0;

}

void empilhar ( struct PILHA *p, float v)
{

    p->topo++;
    p->ptrElemento [p->topo] = v;

}

float desempilhar ( struct PILHA *p )
{

    float aux = p->ptrElemento [p->topo];
    p->topo--;
    return aux;

}

float TopoPilha ( struct PILHA *p )
{

    return p->ptrElemento [p->topo];

}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct PILHA PilhaMain;
    int tamanho, op;
    float valor;

    printf( "\nDigite o tamanho da pilha: " );
    scanf( "%d", &tamanho );
    system("cls");

    CriaPilha (&PilhaMain, tamanho);

    while( 1 )
    {
        printf("\n 1- Empilhar\n");
        printf(" 2- Desempilhar\n");
        printf(" 3- Mostrar o topo \n");
        printf(" 4- sair\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:

            if( PilhaCheia( &PilhaMain ) == 1 )
            {
                system("cls");
                printf("\nPilha cheia \n");
                system("pause > nul");
                system("cls");
            }

            else
            {
                system("cls");
                printf("\nDigite o valor: ");
                scanf("%f", &valor);
                empilhar (&PilhaMain, valor);
                system("cls");
            }
            break;

        case 2:
            if ( PilhaDescarregada(&PilhaMain) == 1 )
            {
                system("cls");
                printf( "\nPilha vazia \n" );
                system("pause > nul");
                system("cls");
            }
            else
            {
                valor = desempilhar (&PilhaMain);
                system("cls");
                printf ( "\nO valor %.1f foi desempilhado\n", valor );
                system("pause > nul");
                system("cls");
            }
            break;

        case 3:
            if ( PilhaDescarregada (&PilhaMain) == 1 )
            {
                system("cls");
                printf( "\nPilha vazia\n" );
                system("pause > nul");
                system("cls");
            }

            else
            {
                system("cls");
                valor = TopoPilha (&PilhaMain);
                printf ( "\nTopo: %.1f\n", valor );
                system("pause > nul");
                system("cls");
            }
            break;

        case 4:
            system("cls");
            exit(0);

        default:
            system("cls");
            printf( "\nOpção inválida, por favor digite uma opção válida \n" );
            system("pause > nul");
            system("cls");
        }
    }

}
