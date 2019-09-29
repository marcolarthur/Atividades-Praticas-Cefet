#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct LISTA{
	int num;
	struct LISTA *prox;
};
typedef struct LISTA lista;

int tam;

void iniciar(lista *LISTA);
int menu(void);
void opcao(lista *LISTA, int op);
lista *criaNo();
void inserirFim(lista *LISTA);
void inserirInicio(lista *LISTA);
void exibe(lista *LISTA);
void liberar(lista *LISTA);
void inserir (lista *LISTA);
lista *RemoverInicio(lista *LISTA);
lista *RemoverFim(lista *LISTA);
lista *retirar(lista *LISTA);


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
	lista *LISTA = (lista *) malloc(sizeof(lista));
	if(!LISTA){
		printf("Memória indisponível\n");
		system("pause > nul");
		system("cls");
		exit(1);
	}else{
	iniciar(LISTA);
	int opt;

	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);

	free(LISTA);
	return 0;
	}
}

void iniciar(lista *LISTA)
{
	LISTA->prox = NULL;
	tam=0;
}

int menu(void)
{
	int opt;

	printf("  *****MENU*****\n");
	printf("1- Limpar lista\n");
	printf("2- Mostrar lista\n");
	printf("3- Adicionar lista no inicio\n");
	printf("4- Adicionar node no final\n");
	printf("5- Escolher posição para inserir\n");
	printf("6- Remover elemento do início\n");
	printf("7- Remover elemento do fim\n");
	printf("8- Escolher posição para remover elemento\n");
	printf("0- Sair\n");
	printf("Digite a opção: "); scanf("%d", &opt);
	system("cls");

	return opt;
}

void opcao(lista *LISTA, int op)
{
	lista *tmp;
	switch(op){
		case 0:
			liberar(LISTA);
			break;

		case 1:
			liberar(LISTA);
			iniciar(LISTA);
			break;

		case 2:
			exibe(LISTA);
			break;

		case 3:
			inserirInicio(LISTA);
			break;

		case 4:
			inserirFim(LISTA);
			break;

		case 5:
			inserir(LISTA);
			break;

		case 6:
			tmp= RemoverInicio(LISTA);
			printf("Elemento retirado: %3d\n\n", tmp->num);
			system("pause > nul");
            system("cls");
			break;

		case 7:
			tmp= RemoverFim(LISTA);
			printf("Elemtnto retirado: %3d\n\n", tmp->num);
			system("pause > nul");
            system("cls");
			break;

		case 8:
			tmp= retirar(LISTA);
			printf("Elemento retirado: %3d\n\n", tmp->num);
			system("pause > nul");
            system("cls");
			break;

		default:
			printf("Por favor, digite um comando válido\n\n");
			system("pause > nul");
            system("cls");
	}
}

int vazia(lista *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

lista *aloca()
{
	lista *novo=(lista *) malloc(sizeof(lista));
	if(!novo){
		printf("Memória indisponível\n");
		system("pause > nul");
		system("cls");
		exit(1);
	}else{
		printf("Digite o elemento: ");
		scanf("%d", &novo->num);
		system("cls");
		return novo;
	}
}


void inserirFim(lista *LISTA)
{
	lista *novo=aloca();
	novo->prox = NULL;

	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		lista *tmp = LISTA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
	tam++;
}

void inserirInicio(lista *LISTA)
{
	lista *novo=aloca();
	lista *oldHead = LISTA->prox;

	LISTA->prox = novo;
	novo->prox = oldHead;

	tam++;
}

void exibe(lista *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia\n\n");
		system("pause > nul");
		system("cls");
		return ;
	}

	lista *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < tam ; count++)
		printf("  ^  ");
	printf("\nOrdem:");
	for(count=0 ; count < tam ; count++)
		printf("%5d", count+1);


	printf("\n\n");
	system("pause > nul");
    system("cls");
}

void liberar(lista *LISTA)
{
	if(!vazia(LISTA)){
		lista *proxNode,
			  *atual;

		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

void inserir(lista *LISTA)
{
	int pos,
		count;
	printf("Digite a posição, [1 -- %d] desejada para inserir o elemento: ", tam);
	scanf("%d", &pos);
	system("cls");

	if(pos>0 && pos <= tam){
		if(pos==1)
			inserirInicio(LISTA);
		else{
			lista *atual = LISTA->prox,
				 *anterior=LISTA;
			lista *novo=aloca();

			for(count=1 ; count < pos ; count++){
					anterior=atual;
					atual=atual->prox;
			}
			anterior->prox=novo;
			novo->prox = atual;
			tam++;
		}

	}else
		printf("Elemento não encontrado\n\n");
		system("pause > nul");
		system("cls");
}

lista *RemoverInicio(lista *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista vazia\n");
		system("pause > nul");
		system("cls");
		return NULL;
	}else{
		lista *tmp = LISTA->prox;
		LISTA->prox = tmp->prox;
		tam--;
		return tmp;
	}

}

lista *RemoverFim(lista *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista vazia\n\n");
		system("pause > nul");
		system("cls");
		return NULL;
	}else{
		lista *ultimo = LISTA->prox,
			 *penultimo = LISTA;

		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}

		penultimo->prox = NULL;
		tam--;
		return ultimo;
	}
}

lista *retirar(lista *LISTA)
{
	int opt,
		count;
	printf("Digite a posição, [1 -- %d] desejada para retirar o elemento: ", tam);
	scanf("%d", &opt);
		system("cls");

	if(opt>0 && opt <= tam){
		if(opt==1)
			return RemoverInicio(LISTA);
		else{
			lista *atual = LISTA->prox,
				 *anterior=LISTA;

			for(count=1 ; count < opt ; count++){
				anterior=atual;
				atual=atual->prox;
			}

		anterior->prox=atual->prox;
		tam--;
		return atual;
		}

	}else{
		printf("Elemento não encontrado\n\n");
		system("pause > nul");
		system("cls");
		return NULL;
	}
}
