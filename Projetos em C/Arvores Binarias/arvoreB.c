#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 3 

typedef struct NoB {
    int chaves[M - 1];        
    struct NoB* filhos[M];     
    int n;                     
    bool ehFolha;              
} NoB;


NoB* criarNo(bool ehFolha) {
    NoB* novo = (NoB*)malloc(sizeof(NoB));
    novo->ehFolha = ehFolha;
    novo->n = 0;
    for (int i = 0; i < M; i++) {
        novo->filhos[i] = NULL;
    }
    return novo;
}


void percorrer(NoB* no) {
    if (no == NULL) return;
    
    int i;
    for (i = 0; i < no->n; i++) {
        
        if (!no->ehFolha) {
            percorrer(no->filhos[i]);
        }
        printf(" %d", no->chaves[i]);
    }
    
    if (!no->ehFolha) {
        percorrer(no->filhos[i]);
    }
}


void dividirFilho(NoB* pai, int i, NoB* filhoCheio) {
    NoB* novoIrmao = criarNo(filhoCheio->ehFolha);
    int T = M / 2;
    novoIrmao->n = T;

   
    for (int j = 0; j < T; j++) {
        novoIrmao->chaves[j] = filhoCheio->chaves[j + T + (M % 2 == 0 ? 0 : 1)];
    }

   
    if (!filhoCheio->ehFolha) {
        for (int j = 0; j <= T; j++) {
            novoIrmao->filhos[j] = filhoCheio->filhos[j + T + (M % 2 == 0 ? 0 : 1)];
        }
    }

    filhoCheio->n = M - 1 - T - 1; 

   
    for (int j = pai->n; j >= i + 1; j--) {
        pai->filhos[j + 1] = pai->filhos[j];
    }
    pai->filhos[i + 1] = novoIrmao;

  
    for (int j = pai->n - 1; j >= i; j--) {
        pai->chaves[j + 1] = pai->chaves[j];
    }
    pai->chaves[i] = filhoCheio->chaves[T];
    pai->n = pai->n + 1;
}


void inserirNaoCheio(NoB* no, int k) {
    int i = no->n - 1;

    if (no->ehFolha) {
        
        while (i >= 0 && no->chaves[i] > k) {
            no->chaves[i + 1] = no->chaves[i];
            i--;
        }
        no->chaves[i + 1] = k;
        no->n = no->n + 1;
    } else {
        
        while (i >= 0 && no->chaves[i] > k) {
            i--;
        }
        
       
        if (no->filhos[i + 1]->n == M - 1) {
            dividirFilho(no, i + 1, no->filhos[i + 1]);
            if (no->chaves[i + 1] < k) {
                i++;
            }
        }
        inserirNaoCheio(no->filhos[i + 1], k);
    }
}


NoB* inserir(NoB* raiz, int k) {
    if (raiz == NULL) {
        raiz = criarNo(true);
        raiz->chaves[0] = k;
        raiz->n = 1;
        return raiz;
    }

   
    if (raiz->n == M - 1) {
        NoB* novaRaiz = criarNo(false);
        novaRaiz->filhos[0] = raiz;
        dividirFilho(novaRaiz, 0, raiz);

        int i = 0;
        if (novaRaiz->chaves[0] < k) {
            i++;
        }
        inserirNaoCheio(novaRaiz->filhos[i], k);
        return novaRaiz; 
    } else {
        inserirNaoCheio(raiz, k);
        return raiz;
    }
}

int main() {
    NoB* raiz = NULL;

    printf("Inserindo chaves em C: 50, 20, 70, 10, 30\n");
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 30);

    printf("Arvore B em ordem:");
    percorrer(raiz);
    printf("\n");

    return 0;
}