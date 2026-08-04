#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    int altura;
    struct no *esq;
    struct no *dir;
}No;

int maior(int a, int b){
    return (a > b) ? a : b;
}

int altura(No *no){
    if(no == NULL)
        return 0;

    return no->altura;
}

No* novoNo(int valor){
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura = 1;

    return novo;
}

int fatorBalanceamento(No *no){
    if(no == NULL)
        return 0;

    return altura(no->esq) - altura(no->dir);
}

No* rotacaoDireita(No *y){
    No *x = y->esq;
    No *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = maior(altura(y->esq), altura(y->dir)) + 1;
    x->altura = maior(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

No* rotacaoEsquerda(No *x){
    No *y = x->dir;
    No *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = maior(altura(x->esq), altura(x->dir)) + 1;
    y->altura = maior(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

No* inserir(No *raiz, int valor){

    if(raiz == NULL)
        return novoNo(valor);

    if(valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);

    else if(valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    else
        return raiz;

    raiz->altura =
        1 + maior(altura(raiz->esq), altura(raiz->dir));

    int fb = fatorBalanceamento(raiz);

    if(fb > 1 && valor < raiz->esq->valor)
        return rotacaoDireita(raiz);

    if(fb < -1 && valor > raiz->dir->valor)
        return rotacaoEsquerda(raiz);

    if(fb > 1 && valor > raiz->esq->valor){
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    if(fb < -1 && valor < raiz->dir->valor){
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void imprimirEmOrdem(No *raiz){
    if(raiz){
        imprimirEmOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->dir);
    }
}

int main(){

    No *raiz = NULL;

    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);

    printf("Arvore AVL em ordem:\n");
    imprimirEmOrdem(raiz);

    return 0;
}