#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	float num;
	struct no *proximo;
}No;

typedef struct{
	No *topo;

}Pilha;

void criar_pilha(Pilha *p){
	p -> topo = NULL;

}

void empilhar(Pilha *p, float valor){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo){
		novo -> num = valor;
		novo -> proximo = p -> topo;
		p -> topo = novo;
		
	}else{
		printf("\nErro ao alocar memória!!");
	}
	

No* desempilhar(Pilha *p){
	if(p -> topo){
		No *remover = p -> topo;
		p -> topo = remover -> proximo;
		return remover;
	}else{
		printf("\nPilha vazia!\n");
		
	}
	return NULL;
}

float operacao(float a, float b, char x){
	switch(x){
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case '/':
			return a / b;
			break;
		case '*':
			return a * b;
			break;
		default:
			return 0.0;
	}
}


float resolver_expressao(char exp[]){
	char *pt;
	float num;
	Pilha pilha;
	criar_pilha(&pilha);
	
	pt = strtok(exp, " ");
	while (pt){
		if(pt[0] == "+" || pt[0] == "-" || pt[0] == "*" ||pt[0] == "/" ){
			No *n1 = desenpilhar(&pilha);
			No *n2 = desempilhar(&pilha);
			
			if(n1 == NULL || n2 == NULL){
                printf("\nErro na expressao!\n");
                return 0;
            }
			
			num = operacao(n2 -> num, n1 -> num, pt[0]);
			
			free(n1);
			free(n2);
			empilhar(&pilha, num);
			
		}else{
			num = strtol(pt, NULL, 10);
			empilhar(&pilha, num);
		}
		pt = strtok(NULL, " ");
	}
	
	No *resultado = desempilhar(&pilha);

    if(resultado == NULL) return 0;

    num = resultado->num;
    free(resultado);

    return num;
}


int main(){
    char exp[100];

    printf("Digite a expressao pos-fixa (ex: 3 4 + 2 *):\n");
    fgets(exp, 100, stdin);

    // remover \n
    exp[strcspn(exp, "\n")] = 0;

    printf("Resultado: %.2f\n", resolver_expressao(exp));

    return 0;

}