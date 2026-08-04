#include <iostream>
using namespace std;

struct No{
    int valor;
    No *proximo;
    No *anterior;
};

struct Lista{
    No *inicio;
    int tam;
};


void inserirInicio(Lista *lista, int valor){
    No *novo = new No();

    novo->valor = valor;
    novo->proximo = lista->inicio;
    novo->anterior = nullptr;

    if(lista->inicio){
        lista->inicio->anterior = novo;
    }

    lista->inicio = novo;
    lista->tam++;
}


void inserirMeio(Lista *lista, int valor, int ant){
    No *novo = new No();
    novo->valor = valor;

    if(lista->inicio == nullptr){
        novo->proximo = nullptr;
        novo->anterior = nullptr;
        lista->inicio = novo;
    }else{
        No *aux = lista->inicio;

        while(aux->valor != ant && aux->proximo){
            aux = aux->proximo;
        }

        novo->proximo = aux->proximo;

        if(aux->proximo){
            aux->proximo->anterior = novo;
        }

        novo->anterior = aux;
        aux->proximo = novo;
    }

    lista->tam++;
}


void inserirFinal(Lista *lista, int valor){
    No *novo = new No();
    novo->valor = valor;
    novo->proximo = nullptr;

    if(lista->inicio == nullptr){
        lista->inicio = novo;
        novo->anterior = nullptr;
    }else{
        No *aux = lista->inicio;

        while(aux->proximo){
            aux = aux->proximo;
        }

        aux->proximo = novo;
        novo->anterior = aux;
    }

    lista->tam++;
}


void inserirOrdenado(Lista *lista, int valor){
    No *novo = new No();
    novo->valor = valor;

    if(lista->inicio == nullptr){
        novo->proximo = nullptr;
        novo->anterior = nullptr;
        lista->inicio = novo;
    }
    else if(valor < lista->inicio->valor){
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        novo->anterior = nullptr;
        lista->inicio = novo;
    }
    else{
        No *aux = lista->inicio;

        while(aux->proximo && valor > aux->proximo->valor){
            aux = aux->proximo;
        }

        novo->proximo = aux->proximo;

        if(aux->proximo){
            aux->proximo->anterior = novo;
        }

        novo->anterior = aux;
        aux->proximo = novo;
    }

    lista->tam++;
}

void removerO(Lista *lista, int num){
    if(lista->inicio == nullptr) return;

    No *aux = lista->inicio;
    No *remover = nullptr;

    if(lista->inicio->valor == num){
        remover = lista->inicio;
        lista->inicio = remover->proximo;

        if(lista->inicio){
            lista->inicio->anterior = nullptr;
        }
    }else{
        while(aux->proximo && aux->proximo->valor != num){
            aux = aux->proximo;
        }

        if(aux->proximo){
            remover = aux->proximo;
            aux->proximo = remover->proximo;

            if(aux->proximo){
                aux->proximo->anterior = aux;
            }
        }
    }

    if(remover){
        delete remover;
        lista->tam--;
    }
}


No* buscar(Lista *lista, int num){
    No *aux = lista->inicio;

    while(aux && aux->valor != num){
        aux = aux->proximo;
    }

    return aux;
}

void imprimir(Lista *l){
    No *aux = l->inicio;

    cout << "\nTamanho da lista: " << l->tam << endl;

    while(aux){
        cout << aux->valor << " ";
        aux = aux->proximo;
    }

    cout << "\n\n";
}


No* ultimo(Lista *lista){
    No *aux = lista->inicio;

    if(!aux) return nullptr;

    while(aux->proximo){
        aux = aux->proximo;
    }

    return aux;
}


void imprimirAoContrario(Lista *l){
    No *aux = ultimo(l);

    cout << "\nTamanho da lista: " << l->tam << endl;

    while(aux){
        cout << aux->valor << " ";
        aux = aux->anterior;
    }

    cout << "\n\n";
}


int main(){
    Lista lista;
    lista.inicio = nullptr;
    lista.tam = 0;

    int opcao, valor, ant;

    do{
        cout << "\n=== MENU ===\n";
        cout << "1 - Inserir no inicio\n";
        cout << "2 - Inserir no meio\n";
        cout << "3 - Inserir no final\n";
        cout << "4 - Inserir ordenado\n";
        cout << "5 - Remover\n";
        cout << "6 - Exibir lista\n";
        cout << "7 - Imprimir ao contrario\n";
        cout << "8 - Buscar\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        if(opcao == 1){
            cout << "Valor: ";
            cin >> valor;
            inserirInicio(&lista, valor);
        }
        else if(opcao == 2){
            cout << "Valor: ";
            cin >> valor;
            cout << "Referencia: ";
            cin >> ant;
            inserirMeio(&lista, valor, ant);
        }
        else if(opcao == 3){
            cout << "Valor: ";
            cin >> valor;
            inserirFinal(&lista, valor);
        }
        else if(opcao == 4){
            cout << "Valor: ";
            cin >> valor;
            inserirOrdenado(&lista, valor);
        }
        else if(opcao == 5){
            cout << "Valor: ";
            cin >> valor;
            removerO(&lista, valor);
        }
        else if(opcao == 6){
            imprimir(&lista);
        }
        else if(opcao == 7){
            imprimirAoContrario(&lista);
        }
        else if(opcao == 8){
            cout << "Valor: ";
            cin >> valor;

            No *res = buscar(&lista, valor);

            if(res){
                cout << "Valor encontrado!\n";
            }else{
                cout << "Valor nao encontrado!\n";
            }
        }

    }while(opcao != 0);

    return 0;
}