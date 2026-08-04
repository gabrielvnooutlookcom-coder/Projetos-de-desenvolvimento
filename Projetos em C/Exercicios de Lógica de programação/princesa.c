#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 4

	struct Turma{
	char aluno[20];
	int rga;
	float media;
	};
 	
 	typedef struct Turma Turma;
 	
int main(){

    setlocale(LC_ALL,"Portuguese");
    
    Turma lista[TAM];
    int i;
    int mediaMaior = 0, mediaMenor = 0;
    
    for(i = 0; i < TAM; i++){
    	printf("Escreva seus dados (%d):\n",i+1);
    	puts("Nome: ");
    	scanf(" %20[^\n]",lista[i].aluno);
    	fflush(stdin);
    	
    	puts("RGA: ");
    	scanf("%d",&lista[i].rga);
    	fflush(stdin);
    	
    	puts("Média: ");
    	scanf("%f",&lista[i].media);
    	fflush(stdin);
    	
	}
	system("cls");
	
	for(i = 0; i < TAM; i++){
	  	if (lista[i].media > lista[mediaMaior].media){
	  		mediaMaior = i;
    	}
    	if(lista[i].media < lista[mediaMenor].media){
    		mediaMenor = i;
		}
	}
	
	
		printf("----------------MELHOR ALUNO----------------\n");
		printf("Aluno:%s\n",lista[mediaMaior].aluno);
		printf("RGA: %d\n",lista[mediaMaior].rga);
	 	printf("Média: %.2f\n",lista[mediaMaior].media);
	 	printf("--------------------------------------------\n");
		

		printf("\n----------------PIOR ALUNO-----------------\n");
		printf("Aluno: %s\n",lista[mediaMenor].aluno);
	 	printf("RGA: %d\n",lista[mediaMenor].rga);
	 	printf("Média: %.2f\n",lista[mediaMenor].media);
	 	printf("---------------------------------------------");
		
	
	return 0;
	}