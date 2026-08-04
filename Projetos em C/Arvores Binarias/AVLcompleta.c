#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *esquerda, *direita;
	short altura;
}No;

No* novoNo(int x){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo){
		novo->valor = x;
		novo->esquerda = NULL;
		novo->direita = NULL;
		novo->altura = 0;
	}else{
		printf("\nERRO ao alocar nó em novoNo!\n");
	}
	return novo;
}

short maior(short a, short b){
	return (a > b)? a: b;
}

short alturaDoNo(No *no){
	if(no == NULL)
		return -1;
	else
		return no->altura;
}

short fatorBalanciamento(No *no){
	if(no)
		return(alturaDoNo(no->esquerda) - alturaDoNo(no->direita));
	else
		return 0;
}

No* rotacaoDireita(No *r){
	No *y, *f;
	
	y = r->esquerda;
	f = y->direita;
	
	y->direita = r;
	r->esquerda = f;
	
	r->altura = maior(alturaDoNo(r->esquerda), alturaDoNo(r->direita)) + 1;
	y->altura = maior(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;
}


No* rotacaoEsquerda(No *r){
	No *y, *f;
	
	y = r->direita;
	f = y->esquerda;
	
	y->esquerda = r;
	r->direita = f;
	
	r->altura = maior(alturaDoNo(r->esquerda), alturaDoNo(r->direita)) + 1;
	y->altura = maior(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;
}


No* rotacaoEsquerdaDireita(No *r){
	r->esquerda = rotacaoEsquerda(r->esquerda);
	return rotacaoDireita(r);
}

No* rotacaoDireitaEsquerda(No *r){
	r->esquerda = rotacaoDireita(r->esquerda);
	return rotacaoEsquerda(r);
}

No* balancear(No *raiz){
	short fb = fatorBalanciamento(raiz);
	
	//rotação esquerda
	if(fb < -1 && fatorBalanciamento (raiz->direita) <= 0)
		raiz = rotacaoEsquerda(raiz);
	//rotação direita
	else if(fb > 1 && fatorBalanciamento (raiz->esquerda) >= 0)
		raiz = rotacaoDireita(raiz);
	//rotação dupla esquerda
	else if(fb > 1 && fatorBalanciamento (raiz->esquerda) < 0)
		raiz = rotacaoEsquerdaDireita(raiz);
	//rotação dupla direita
	else if(fb < -1 && fatorBalanciamento (raiz->direita) > 0)
		raiz = rotacaoDireitaEsquerda(raiz);
	return raiz;
}

No* inserir(No *raiz, int x){

    if(raiz == NULL){
        return novoNo(x);
    }
    else{
        if(x < raiz->valor)
            raiz->esquerda = inserir(raiz->esquerda, x);

        if(x > raiz->valor)
            raiz->direita = inserir(raiz->direita, x);

    }
    
    raiz->altura = maior(alturaDoNo(raiz->esquerda), alturaDoNo(raiz->direita)) + 1;
    
    raiz = balancear(raiz);
    
    return raiz;
}

No* remover(No *raiz, int chave){
	if(raiz == NULL){
		printf("Valor não encontrado!\n");
		return NULL;
	}else{
		if(raiz->valor == chave){
			//remover nós sem filho(nó folha)
			if(raiz->esquerda == NULL && raiz->direita == NULL){
				free(raiz);
				return NULL;
			}else{
				//remover nós com apenas 1 filho
				if(raiz->esquerda == NULL || raiz->direita == NULL){
					No *aux;
					if(raiz->esquerda != NULL)
						aux = raiz->esquerda;
					else
						aux = raiz->direita;
					free(raiz);
					return aux;
				}else{
					//remover nós com 2 filhos
					No *aux = raiz->esquerda;
					while(aux->direita != NULL)
						aux = aux->direita;
					raiz->valor = aux->valor;
					aux->valor = chave;
					raiz->esquerda = remover(raiz->esquerda,chave);
					return raiz;
				}
			}
		}else{
			if(chave < raiz->valor)
				raiz->esquerda = remover(raiz->esquerda, chave);
			else
				raiz->direita = remover(raiz->direita, chave);
			
		}
		raiz->altura = maior(alturaDoNo(raiz->esquerda), alturaDoNo(raiz->direita)) + 1;
	    
	    raiz = balancear(raiz);
	    
	    return raiz;
		
	}
}

void imprimir(No *raiz, int nivel){
	int i;
	if(raiz){
		imprimir(raiz->direita, nivel + 1);
		printf("\n\n");
		
		for(i = 0; i < nivel; i++)
			printf("\t");
			
		printf("%d", raiz->valor);
		imprimir(raiz->esquerda, nivel + 1);
	}	
}

int main(){
	int op, valor;
	No *raiz = NULL;
	
	do{
	
		printf("\n=== MENU ===\n");
	        printf("1 - Inserir \n");
	        printf("2 - Remover\n");
	        printf("3 - Imprimir\n");
	        printf("0 - Sair\n");
	        printf("Escolha: ");
	        scanf("%d", &op);
	        
	    if(op == 1){
	    	printf("Digite o valor a ser inserido: ");
	    	scanf("%d",&valor);
	    	raiz = inserir(raiz,valor);
		
		}else if(op == 2){
			printf("Digite um valor para ser removido: ");
			scanf("%d", &valor);
			raiz = remover(raiz, valor);
		
		}else if(op == 3){
			imprimir(raiz, 1);
		
		}else{
			printf("Saindo...");
		}
	        
    }while(op != 0);
}
