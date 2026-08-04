#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 4

struct Registro{
    int num;
    char nome[20];
    float saldo;
};
typedef struct Registro Registro;

int main(){
    setlocale(LC_ALL, "Portuguese");

    Registro lista[TAM];
    int i, j, resposta = 0, totalContas = 0;
    char busca[20];

    while(resposta != 4){
        printf("MENU DE OPÇÕES:\n");
        printf("==================\n");
        printf("[1] Cadastrar contas.\n");
        printf("[2] Visualizar todas as contas do cliente.\n");
        printf("[3] Excluir a conta com menor saldo.\n");
        printf("[4] Sair.\n");
        printf("==================\n");
        printf("RESPOSTA: ");
        scanf("%d", &resposta);
        system("cls");

        if (resposta == 1){
            if(totalContas >= TAM){
                printf("\nLimite de contas atingido!\n");
            }else{
                Registro nova;
                int repetido = 0;

                printf("\nNúmero da conta: ");
                scanf("%d", &nova.num);
                fflush(stdin);

                for(i = 0; i < totalContas; i++){
                    if (lista[i].num == nova.num){
                        repetido = 1;
                        break;
                    }
                }

                if(repetido){
                    printf("Erro: Já existe uma conta com esse número!\n");
                }else{
                    printf("Nome do cliente: ");
                    scanf(" %20[^\n]", nova.nome);
                    fflush(stdin);

                    printf("Saldo inicial: ");
                    scanf("%f", &nova.saldo);
                    fflush(stdin);

                    lista[totalContas] = nova;
                    totalContas++;

                    printf("\nConta cadastrada com sucesso!\n");
                }
            }
        }else if(resposta == 2){
            if(totalContas == 0) {
                printf("Nenhuma conta cadastrada!\n");
            }else{
                printf("\nDigite o nome do cliente: ");
                scanf(" %20[^\n]", busca);

                int encontrou = 0;
                printf("\nContas de %s:\n", busca);

                for(i = 0; i < totalContas; i++){
                    if(strcmp(lista[i].nome, busca) == 0){
                        printf("Conta: %d | Saldo: %.2f\n", lista[i].num, lista[i].saldo);
                        encontrou = 1;
                    }
                }

                if(!encontrou){
                    printf("Nenhuma conta encontrada para esse cliente.\n");
                }
            }
        }else if(resposta == 3){
            if(totalContas == 0){
                printf("\nNenhuma conta cadastrada!\n");
            }else{
                int indiceMenor = 0;

                for (i = 1; i < totalContas; i++){
                    if (lista[i].saldo < lista[indiceMenor].saldo)
                        indiceMenor = i;
                }

                printf("\nConta com menor saldo excluída:\n");
                printf("Conta: %d | Cliente: %s | Saldo: %.2f\n",lista[indiceMenor].num,lista[indiceMenor].nome,lista[indiceMenor].saldo);

                for (j = indiceMenor; j < totalContas - 1; j++){
                    lista[j] = lista[j + 1];
                }

                totalContas--;
                printf("Conta removida com sucesso!\n");
            }
        } 
        else if(resposta == 4){
            printf("\nEncerrando o programa...\n");
        }else{
            printf("\nOpção inválida! Tente novamente.\n");
        }
    }

    return 0;
}