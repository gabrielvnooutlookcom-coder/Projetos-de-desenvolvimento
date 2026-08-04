#include <stdio.h>
#include <stdlib.h>


typedef struct No{
	int valor;
	struct No *proximo;
	struct No *anterior;
}No;

typedef struct{
	No *inicio;
	int tam;
}Lista;

void inserirInicio(Lista *lista, int valor){
	No *novo = (No*)malloc(sizeof(No));
	novo -> valor = valor; //(*novo).valor = valor
	
	novo -> proximo = lista -> inicio;
	novo -> anterior = NULL;
	if(lista->inicio){
		lista->inicio->anterior = novo;
	}
	lista -> inicio = novo;
	lista -> tam++;
}

void inserirMeio(Lista *lista, int valor, int ant){
	No *aux, *novo = (No*)malloc(sizeof(No));
	novo -> valor = valor;
	
	if(lista -> inicio == NULL){
		novo -> proximo = NULL;
		novo->anterior = NULL;
		lista -> inicio = novo;
	
	}else{
		aux = lista -> inicio;
		while(aux -> valor != ant && aux -> proximo){
			aux = aux -> proximo;
		}
		novo -> proximo = aux -> proximo;
		if(aux->proximo){
			aux->proximo->anterior = novo;
		}
		novo->anterior = aux;
		aux -> proximo = novo;
	}
	lista -> tam++;
}

void inserirFinal(Lista *lista, int valor){
	No *no, *novo = (No*)malloc(sizeof(No));
	novo -> valor = valor; //(*novo).valor = valor
	novo -> proximo = NULL;
	
	if(lista -> inicio == NULL){
		lista -> inicio = novo;
		novo->anterior = NULL;
		
	}else{
		no = lista -> inicio;
		while(no -> proximo != NULL){
			no = no -> proximo;
		}
		no -> proximo = novo;
		novo->anterior = no;
	}
	lista -> tam++;
}

void inserirOrdenado(Lista *lista, int valor){
	No *aux, *novo = (No*)malloc(sizeof(No));
	novo -> valor = valor;
	
	if(novo){
		if(lista -> inicio == NULL){
			novo -> proximo = NULL;
			novo -> anterior= NULL;
			lista -> inicio = novo;
		}else if(novo -> valor < lista -> inicio -> valor){
			novo -> proximo = lista -> inicio;
			lista->inicio->anterior = novo;
			lista -> inicio = novo;
		}else{
			aux = lista -> inicio;
			while(aux -> proximo && novo -> valor > aux -> proximo -> valor){
				aux = aux -> proximo;
			}
			novo->proximo = aux->proximo;
			if(aux->proximo){
				aux->proximo->anterior = novo;
			}
			
			novo->anterior = aux; 
			aux->proximo = novo;
		}
		lista -> tam++;
	}else{
		printf("Memoria não alocada com sucesso!");
	}
}

void removerO(Lista *lista, int num){
	No  *aux ,*remover = NULL;
	
	if(lista->inicio){
		if(lista->inicio->valor == num){
			remover = lista->inicio;
			lista->inicio = remover->proximo;
			if(lista->inicio){
				lista->inicio->anterior = NULL;
			}
		}else{
			aux = lista->inicio;
			while(aux->proximo && aux->proximo->valor != num){
				aux = aux->proximo;
			}
			if(aux->proximo){
				remover = aux->proximo;
				aux->proximo = remover->proximo;
				if(aux->proximo){
					aux->proximo->anterior = aux;
				}
			}
			
		}
		if(remover){
			lista->tam--;
			free(remover);
		}
	}else{
		printf("Memoria não alocada com sucesso!");
	}
}

No* buscar(Lista *lista, int num){
	No *aux, *achou = NULL;
	
	aux = lista->inicio;
	while(aux && aux->valor != num){
		aux = aux->proximo;
	}
	if(aux){
		achou = aux;
	}
	
	return achou;
}



void imprimir(Lista *l){
	No *aux = l -> inicio;
	printf("\n Tamanho da lista: %d\n",l -> tam);
	while(aux != NULL){
		printf("%d ",aux -> valor);
		aux = aux -> proximo;
	}
	printf("\n\n");
}

No* ultimo(Lista *lista){
	No *aux = lista->inicio;
	
	while(aux->proximo){
		aux = aux->proximo;
	}
	return aux;
}

void imprimirAoContrario(Lista *l){
	No *aux = ultimo(l);
	
	printf("\n Tamanho da lista: %d\n",l -> tam);
	
	while(aux != NULL){
		printf("%d ",aux -> valor);
		aux = aux -> anterior;
	}
	printf("\n\n");
}

int main(){
	Lista lista;
	int opcao, valor, ant;
	
	
	lista.inicio = NULL;
	lista.tam = 0;
	
	do{
		printf("\n=== MENU ===\n");
        printf("1 - Inserir no incio\n");
        printf("2 - Inserir no meio\n");
        printf("3 - Inserir no final\n");
        printf("4 - Inserir de maneira ordenada\n");
        printf("5 - Excluir de lista ordenada\n");
        printf("6 - Exibir lista\n");
        printf("7 - Imprimir ao contrario\n");
        printf("8 - Buscar na lista\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        if(opcao == 1){
        	printf("Digite o valor a ser inserido:");
        	scanf("%d", &valor);
        	inserirInicio(&lista, valor);
        	
    	}else if(opcao == 2){
        	printf("Digite o valor a ser inserido no meio:");
        	scanf("%d",&valor);
        	printf("Digite um valor de referencia:");
        	scanf("%d",&ant);
        	inserirMeio(&lista, valor, ant);
        
		}else if(opcao == 3){
        	printf("Digite o valor a ser inserido no final:");
        	scanf("%d",&valor);
        	inserirFinal(&lista, valor);
        	
        }else if(opcao == 4){
        	printf("Digite o valor a ser inserido de maneira ordenada:");
        	scanf("%d",&valor);
        	inserirOrdenado(&lista, valor);
        	
		}else if(opcao == 5){
			printf("Digite o valor a ser excluido da lista ordenada:");
        	scanf("%d",&valor);
        	removerO(&lista, valor);
		
        }else if(opcao == 6){
			imprimir(&lista);
			
		}else if(opcao == 7){
			imprimirAoContrario(&lista);
			
		}else if(opcao == 8){
			printf("Digite o valor q deseja achar na lista:");
        	scanf("%d",&valor);
        	buscar(&lista, valor);
        	
        	No *res = buscar(&lista, valor);

    		if(res){
        		printf("Valor encontrado!\n");
    		}else{
        		printf("Valor nao encontrado!\n");
    		}
			
			
		}else if (opcao == 0){
			printf("Saindo...\n");
			
		}else{
			printf("Opção invalida!\n");
		}
        
        
	}while(opcao != 0);
	
	
	return 0;
}

