#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
} No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
} Lista;


void inserirInicio(Lista *lista, int valor){
    No *novo = malloc(sizeof(No));
    novo->valor = valor;

    if(lista->inicio == NULL){
        novo->proximo = novo;
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->proximo = lista->inicio;
        lista->fim->proximo = novo;
        lista->inicio = novo;
    }

    lista->tam++;
}


void inserirFinal(Lista *lista, int valor){
    No *novo = malloc(sizeof(No));
    novo->valor = valor;

    if(lista->inicio == NULL){
        novo->proximo = novo;
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->proximo = lista->inicio;
        lista->fim->proximo = novo;
        lista->fim = novo;
    }

    lista->tam++;
}

void inserirOrdenado(Lista *lista, int valor){
    No *novo = (No*) malloc(sizeof(No));

    if(!novo){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->valor = valor;

   
    if(lista->inicio == NULL){
        novo->proximo = novo;
        lista->inicio = novo;
        lista->fim = novo;
    }else if(valor < lista->inicio->valor){
        novo->proximo = lista->inicio;
        lista->fim->proximo = novo;
        lista->inicio = novo;
    }else{
        No *aux = lista->inicio;

     
        while(aux->proximo != lista->inicio && aux->proximo->valor < valor){
            aux = aux->proximo;
        }

        
        if(aux == lista->fim){
            novo->proximo = lista->inicio;
            lista->fim->proximo = novo;
            lista->fim = novo;
        }else{
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
}

void removerO(Lista *lista, int num){
    if(lista->inicio == NULL) return;

    No *aux = lista->inicio;
    No *anterior = lista->fim;

    do{
        if(aux->valor == num){

            
            if(aux == lista->inicio && aux == lista->fim){
                lista->inicio = NULL;
                lista->fim = NULL;
                
            }else{
                anterior->proximo = aux->proximo;

                if(aux == lista->inicio)
                    lista->inicio = aux->proximo;

                if(aux == lista->fim)
                    lista->fim = anterior;
            }

            free(aux);
            lista->tam--;
            return;
        }

        anterior = aux;
        aux = aux->proximo;

    }while(aux != lista->inicio);
}


No* buscar(Lista *lista, int num){
    if(lista->inicio == NULL) return NULL;

    No *aux = lista->inicio;

    do{
        if(aux->valor == num)
            return aux;
        aux = aux->proximo;
    }while(aux != lista->inicio);

    return NULL;
}


void imprimir(Lista *lista){
    printf("\nTamanho: %d\n", lista->tam);

    if(lista->inicio == NULL){
        printf("Lista vazia\n");
        return;
    }

    No *aux = lista->inicio;

    do{
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }while(aux != lista->inicio);

    printf("\n");
}


int main(){
    Lista lista;
    int opcao, valor;

    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tam = 0;

    do{
        printf("\n=== MENU ===\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir ordenado\n");
        printf("4 - Remover\n");
        printf("5 - Exibir lista\n");
        printf("6 - Buscar na lista\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserirInicio(&lista, valor);

        }else if(opcao == 2){
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserirFinal(&lista, valor);

        }else if(opcao == 3){
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserirOrdenado(&lista, valor);

        }else if(opcao == 4){
            printf("Digite o valor a remover: ");
            scanf("%d", &valor);
            removerO(&lista, valor);

        }else if(opcao == 5){
            imprimir(&lista);

        }else if(opcao == 6){
            printf("Digite o valor a buscar: ");
            scanf("%d", &valor);

            No *res = buscar(&lista, valor);

            if(res){
                printf("Valor encontrado!\n");
            }else{
                printf("Valor nao encontrado!\n");
            }

        }else if(opcao == 0){
            printf("Saindo...\n");

        }else{
            printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}