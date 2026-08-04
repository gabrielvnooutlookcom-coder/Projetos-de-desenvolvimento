#include <iostream>
using namespace std;

struct No{
    int valor;
    No *proximo;
};

struct Lista{
    No *inicio;
    No *fim;
    int tam;
};

void inserirInicio(Lista *lista, int valor){
    No *novo = new No();
    novo->valor = valor;

    if(lista->inicio == nullptr){
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
    No *novo = new No();
    novo->valor = valor;

    if(lista->inicio == nullptr){
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
    No *novo = new No();

    if(!novo){
        cout << "Erro ao alocar memoria!\n";
        return;
    }

    novo->valor = valor;

    if(lista->inicio == nullptr){
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

    lista->tam++;
}

void removerO(Lista *lista, int num){
    if(lista->inicio == nullptr) return;

    No *aux = lista->inicio;
    No *anterior = lista->fim;

    do{
        if(aux->valor == num){
            if(aux == lista->inicio && aux == lista->fim){
                lista->inicio = nullptr;
                lista->fim = nullptr;
            }else{
                anterior->proximo = aux->proximo;

                if(aux == lista->inicio)
                    lista->inicio = aux->proximo;

                if(aux == lista->fim)
                    lista->fim = anterior;
            }

            delete aux;
            lista->tam--;
            return;
        }

        anterior = aux;
        aux = aux->proximo;

    }while(aux != lista->inicio);
}

No* buscar(Lista *lista, int num){
    if(lista->inicio == nullptr) return nullptr;

    No *aux = lista->inicio;

    do{
        if(aux->valor == num)
            return aux;
        aux = aux->proximo;
    }while(aux != lista->inicio);

    return nullptr;
}

void imprimir(Lista *lista){
    cout << "\nTamanho: " << lista->tam << endl;

    if(lista->inicio == nullptr){
        cout << "Lista vazia\n";
        return;
    }

    No *aux = lista->inicio;

    do{
        cout << aux->valor << " ";
        aux = aux->proximo;
    }while(aux != lista->inicio);

    cout << endl;
}

int main(){
    Lista lista;
    int opcao, valor;

    lista.inicio = nullptr;
    lista.fim = nullptr;
    lista.tam = 0;

    do{
        cout << "\n=== MENU ===\n";
        cout << "1 - Inserir no inicio\n";
        cout << "2 - Inserir no final\n";
        cout << "3 - Inserir ordenado\n";
        cout << "4 - Remover\n";
        cout << "5 - Exibir lista\n";
        cout << "6 - Buscar na lista\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        if(opcao == 1){
            cout << "Digite o valor: ";
            cin >> valor;
            inserirInicio(&lista, valor);

        }else if(opcao == 2){
            cout << "Digite o valor: ";
            cin >> valor;
            inserirFinal(&lista, valor);

        }else if(opcao == 3){
            cout << "Digite o valor: ";
            cin >> valor;
            inserirOrdenado(&lista, valor);

        }else if(opcao == 4){
            cout << "Digite o valor a remover: ";
            cin >> valor;
            removerO(&lista, valor);

        }else if(opcao == 5){
            imprimir(&lista);

        }else if(opcao == 6){
            cout << "Digite o valor a buscar: ";
            cin >> valor;

            No *res = buscar(&lista, valor);

            if(res){
                cout << "Valor encontrado!\n";
            }else{
                cout << "Valor nao encontrado!\n";
            }

        }else if(opcao == 0){
            cout << "Saindo...\n";

        }else{
            cout << "Opcao invalida!\n";
        }

    }while(opcao != 0);

    return 0;
}