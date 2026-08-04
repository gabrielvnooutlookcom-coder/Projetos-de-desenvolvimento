#include <stdio.h>
#include <math.h>

int main() {
    int vetor[10];
    int i, n = 10;
    float soma = 0, soma_quadrados = 0;
    float media, desvio;

  
    	for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
        soma += vetor[i];
        soma_quadrados += vetor[i] * vetor[i];
    	}

    
    media = soma / n;

    
    desvio = sqrt((soma_quadrados / n) - (media * media));

    printf("Média = %.2f\n", media);
    printf("Desvio padrão = %.2f\n", desvio);

    return 0;
	}
	
	

