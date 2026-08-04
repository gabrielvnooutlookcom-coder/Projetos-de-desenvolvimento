#include <stdio.h>
#include <stdlib.h>

	
typedef struct{
int dia, mes, ano;
}Data;

typedef struct{
	char nome[50];
	Data data;
}Pessoa;

typedef struct no{
	Pessoa p;
	struct no *proximo;
}No;

typedef struct{
	No *topo;
	int tam;
}Pilha;

void criar_pilha(Pilha *p){
	p -> topo = NULL;
	p -> tam = 0;
}

Pessoa ler_pessoa(){
	Pessoa p;
	
	printf("\nDigite o nome e a adata de nascimento dd mm aaaa:\n");
	scanf(" %49[^\n] %d %d %d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
	return p;
}

void empilhar(Pilha *p){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo){
		novo -> p = ler_pessoa();
		novo -> proximo = p -> topo;
		p -> topo = novo;
		p -> tam++;
	}else{
		printf("\nErro ao alocar memória!!");
	}
	

No* desempilhar(Pilha *p){
	if(p -> topo){
		No *remover = p -> topo;
		p -> proximo = remover -> proximo;
		p -> tam--;
		return remover;
	}else{
		printf("\nPilha vazia!\n");
		
	}
	return NULL;
}


void imprimir_pessoa(Pessoa p){
	printf("\n Nome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

void imprimir_pilha(Pilha *p){
	No *aux = p -> topo;
	printf("\n--------------- PILHA Tam: ---------------\n", p -> tam);
	while(aux){
		imprimir_pessoa(aux -> p);
		aux = aux -> proximo;
	}
	printf("\n--------------- FIM PILHA ----------------\n");
}

int main(){
	
	No *remover;
	Pilha p;
	int opcao;
	
	criar_pilha(&p);
	
	do{
		printf("\n=== MENU ===\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        if(opcao == 1){
        	empilhar(&p);
        	
    	}else if(opcao == 2){
    		remover = desempilhar(&p);
        	if(remover){
        		printf("\n Elemento removido com sucesso!\n");
        		imprimir_pessoa(remover -> p);
        		free(remover);
			}else{
				printf("\nSem nó a remover!\n");
			}
        
		}else if(opcao == 3){
        	imprimir_pilha(&pilha);
        	
			
		}else if (opcao == 0){
			printf("Saindo...\n");
			
		}else{
			printf("Opção invalida!\n");
		}
        
        
	}while(opcao != 0);
	
	
	
	return 0;
}