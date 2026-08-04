#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 6

struct Registro{
	char nome[30];
	char email[30];
	char cidade[30];
};
typedef struct Registro Registro;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
  Registro lista[TAM];
  int i,encontrado = 0;
  char busca[30];
    
    for(i = 0; i < TAM; i++){
	printf("Digite seus dados:\n");
	puts("Nome: ");
	scanf(" %30[^\n]",lista[i].nome);
	fflush(stdin);
	puts("E-mail: ");
	scanf(" %30[^\n]",lista[i].email);
	fflush(stdin);
	puts("Cidade: ");
	scanf(" %30[^\n]",lista[i].cidade);
	fflush(stdin);
	}
	system("cls");
	
printf("\nDigite o nome da cidade que deseja buscar: ");
scanf(" %30[^\n]", busca);
	
	for(i = 0; i < TAM; i++){
		if(strcmp(lista[i].cidade,busca) == 0){
			printf("Cliente(s): %s",lista[i].nome);
			printf("E-mail: %s",lista[i].email);
			printf("Cidade: %s",lista[i].cidade);
			encontrado = 1;
		}else if(!encontrado){
			printf("\nNenhum cliente foi encontrado na cidade escolhida");
		}
	}
return 0;
}