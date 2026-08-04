#include <stdio.h>
#include <stdlib.h>

#define TAM 31

void inicializarTabela(int t[]){
	int i;
	for(i = 0; i < TAM; i++){
		t[i] = 0;
	}
}

int funcaoHash(int chave){
	return chave % TAM;
}

void inserir (int t[], int valor){
	int id = funcaoHash(valor);
	while(t[id] != 0){
		id = funcaoHash(id + 1);		
	}
	t[id] = valor;
}

// Corrigido: Mudado de void para int, já que a função retorna um valor
int buscar(int t[], int chave){
	int id = funcaoHash(chave);
	while(t[id] != 0){
		if(t[id] == chave)
			return t[id];
		else
			id = funcaoHash(id + 1);
	}
	return 0;
}

void imprimir(int t[]){
	int i;
	// Corrigido: i = TAM transformava o loop em infinito. Mudado para i < TAM
	for(i = 0; i < TAM; i++){
		printf("%d = %d\n", i, t[i]);
	}
}

int main(){
	int tabela[TAM];
	int op, valor; // Corrigido: Declarada a variável 'valor'
    
	inicializarTabela(tabela); // Corrigido: Digitado corretamente o nome da função
	
	do{
		printf("\n=== MENU ===\n");
        printf("1 - Inserir \n");
        printf("2 - Imprimir\n"); // Corrigido: Inprimir -> Imprimir
        printf("3 - Buscar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);
        
        if(op == 1){
        	printf("Digite o valor a ser inserido: ");
        	scanf("%d", &valor);
        	inserir(tabela, valor);
        	
    	}else if(op == 2){
        	printf("Impressao da tabela:\n");
        	imprimir(tabela);
        	// Corrigido: Removida a linha do tamanho(raiz), pois não se aplica a tabelas hash fixas
        	
    	}else if(op == 3){
    		printf("Qual valor vc deseja buscar? ");
    		scanf("%d", &valor);
    		printf("\n");
            
    		// Corrigido: Alterado de 'busca' para 'buscar'
    		if(buscar(tabela, valor) != 0){
    			printf("Resultado da busca: %d\n", buscar(tabela, valor));
			}else{
				printf("Valor nao encontrado\n");
			}
        
        }else if (op == 0){
			printf("Saindo...\n");
			
		}else{
			printf("Opcao invalida!\n");
		}
		
	}while(op != 0);
	
	return 0;
}