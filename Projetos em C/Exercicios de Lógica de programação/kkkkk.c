#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 5

struct Produtos{
    char nome[20];
	float preco;
    int quantidade;
};
typedef struct Produtos Produtos;

int main(){
    setlocale(LC_ALL, "Portuguese");

    Produtos lista[TAM];
    int i, maiorpreco = 0;
	float valortotal = 0;

   for(i = 0; i < TAM; i++){
   printf("Digite o nome do produto:\n");
   scanf(" %20[^\n]",&lista[i].nome);
   fflush(stdin);
   printf("\nDigite o preço do produto:\n");
   scanf("%f",&lista[i].preco);
   fflush(stdin);
   printf("\nDigite a quantidade de unidades do produto:");
   scanf("%d",&lista[i].quantidade);
   fflush(stdin);
  
}
system("cls");
for(i = 0; i < TAM; i++){
	if(lista[i].preco > lista[maiorpreco].preco){
	maiorpreco = i;
		}
	valortotal = valortotal + lista[i].preco;
}
	
	printf("O produto com o maior preco é o %s\n",lista[maiorpreco].nome);
	printf("\nO preço desse produto é:%2f\n",lista[maiorpreco].preco);
    printf("\nO valor total de produtos é:%2f",valortotal);

    return 0;
}