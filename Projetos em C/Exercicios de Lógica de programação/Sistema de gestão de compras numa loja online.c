#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Venda {
    int codigo;
    char produto[50];
    int quantidade;
    char comprador[50];
    char endereco[100];
    char estado[3];
    char entrega[20];
    struct Venda *proximo;
} Venda;

typedef struct Produto {
    char nome[50];
    int quantidade;
} Produto;

Venda *head = NULL;

Produto estoque[100];
int total_produtos = 0;

void adicionar_estoque(char nome[], int qtd) {
    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            estoque[i].quantidade += qtd;
            return;
        }
    }

    strcpy(estoque[total_produtos].nome, nome);
    estoque[total_produtos].quantidade = qtd;
    total_produtos++;
}

int verificar_estoque(char nome[], int qtd) {
    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            if (estoque[i].quantidade >= qtd) {
                estoque[i].quantidade -= qtd;
                return 1;
            } else {
                return 0;
            }
        }
    }
    return -1;
}

void cadastrar(int codigo, char produto[], int qtd, char comprador[], char endereco[], char estado[], char entrega[]) {

    int estoque_ok = verificar_estoque(produto, qtd);

    if (estoque_ok == -1) {
        printf("Produto nao existe no estoque\n");
        return;
    }

    if (estoque_ok == 0) {
        printf("Venda bloqueada: estoque insuficiente\n");
        return;
    }

    Venda *novo = (Venda*) malloc(sizeof(Venda));

    novo->codigo = codigo;
    strcpy(novo->produto, produto);
    novo->quantidade = qtd;
    strcpy(novo->comprador, comprador);
    strcpy(novo->endereco, endereco);
    strcpy(novo->estado, estado);
    strcpy(novo->entrega, entrega);
    novo->proximo = NULL;

    if (head == NULL) {
        head = novo;
    } else {
        Venda *atual = head;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }

    printf("Venda cadastrada\n");
}

void consultar(int codigo) {
    Venda *atual = head;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            printf("Codigo: %d\n", atual->codigo);
            printf("Produto: %s\n", atual->produto);
            printf("Comprador: %s\n", atual->comprador);
            printf("Estado: %s\n", atual->estado);
            printf("Entrega: %s\n", atual->entrega);
            return;
        }
        atual = atual->proximo;
    }

    printf("Venda nao encontrada\n");
}

void alterar(int codigo, char endereco[], char estado[], char entrega[]) {
    Venda *atual = head;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            strcpy(atual->endereco, endereco);
            strcpy(atual->estado, estado);
            strcpy(atual->entrega, entrega);
            printf("Venda alterada\n");
            return;
        }
        atual = atual->proximo;
    }

    printf("Venda nao encontrada\n");
}

void excluir(int codigo) {
    Venda *atual = head;
    Venda *anterior = NULL;

    while (atual != NULL) {
        if (atual->codigo == codigo) {

            if (anterior == NULL) {
                head = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            printf("Venda excluida\n");
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("Venda nao encontrada\n");
}

void imprimir(char entrega[], char estado[]) {
    Venda *atual = head;

    while (atual != NULL) {

        if (strcmp(atual->entrega, entrega) == 0 &&
            strcmp(atual->estado, estado) == 0) {

            printf("%d %s %s\n",
                   atual->codigo,
                   atual->produto,
                   atual->comprador);
        }

        atual = atual->proximo;
    }
}

int main() {

    adicionar_estoque("Livro", 10);
    adicionar_estoque("Mouse", 5);

    cadastrar(1, "Livro", 2, "Ana", "Rua A", "MT", "sedex");
    cadastrar(2, "Mouse", 1, "Carlos", "Rua B", "SP", "carta simples");

    consultar(1);

    alterar(1, "Rua Nova", "MT", "carta simples");

    imprimir("carta simples", "SP");

    excluir(2);

    return 0;
}