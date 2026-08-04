#include <stdio.h>
#include <stdlib.h>


typedef struct No{
	int valor;
	struct No *proximo;
}No;

typedef struct{
	No *inicio, *fim;
	int tam;
}Lista;

void inserirInicio(Lista *lista, int valor){
	No *novo = (No*)malloc(sizeof(No));
	novo -> valor = valor; //(*novo).valor = valor
	
	if(lista -> inicio == NULL){
		novo -> proximo = NULL;
		lista -> inicio = novo;
		lista -> fim = novo;
	}else{
		novo -> proximo = lista -> inicio;
		lista -> inicio = novo;
	}
	lista -> tam++;
}

void inserirFinal(Lista *lista, int valor){
	No *no, *novo = (No*)malloc(sizeof(No));
	novo -> valor = valor; //(*novo).valor = valor
	novo -> proximo = NULL;
	
	if(lista -> inicio == NULL){
		lista -> inicio = novo;
		lista -> fim = novo;
	}else{
		lista -> fim -> proximo = novo;
		lista -> fiim = novo;
	}
	lista -> tam++;
}

void remover(Lista *lista, int valor){
	No *inicio = lista -> inicio;
	No * noARemover = NULL;
	
	if(inicio != NULL && lista -> inicio -> valor == valor){
		noARemover = lista -> inicio;
		lista -> inicio = noARemover -> proximo;
		if(lista -> inicio == NULL){
			lista -> fim = NULL;
		}
	}else{
		while(inicio != NULL && inicio -> proximo != NULL && inicio -> proximo -> valor != valor){
			inicio = inicio -> proximo;
		}
		if(inicio != NULL && inicio -> proximo != NULL){
				noARemover = inicio -> proximo;
				inicio -> proxima = noARemover -> proximo;
				if(inicio -> proximo == NULL){
					lista -> fim = inicio;
				}
				
		}
	}
	if(noARemover){
		free(noARemover);
		lista -> tam--;
	}
}


void imprimir(Lista *l){
	No *inicio = l -> inicio;
	printf("\n Tamanho da lista: %d\n",l -> tam);
	while(inicio != NULL){
		printf("%d ",inicio -> valor);
		inicio = inicio -> proximo;
	}
	printf("\n\n");
}

int main(){
	Lista lista;
	int opcao, valor;
	
	lista.inicio = NULL;
	lista.tam = 0;
	
	do{
		printf("\n=== MENU ===\n");
        printf("1 - Inserir no incio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Exibir Lista\n");
        printf("4 - Excluir\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        if(opcao == 1){
        	printf("Digite o valor a ser inserido:");
        	scanf("%d", &valor);
        	inserirInicio(&lista, valor);
        
		}else if(opcao == 2){
        	printf("Digite o valor a ser inserido no final:");
        	scanf("%d",&valor);
        	inserirFinal(&lista, valor);
        	
		}else if(opcao == 3){
			imprimir(&lista);
			
		}else if(opcao == 4){
			printf("Digite o valor a ser excluido:");
        	scanf("%d",&valor);
        	remover(&lista, valor);
		}
			
		}else if (opcao == 0){
			printf("Saindo...\n");
			
		}else{
			printf("Opção invalida!\n");
		}
        
        
	}while(opcao != 0);
	
	
	return 0;
}
