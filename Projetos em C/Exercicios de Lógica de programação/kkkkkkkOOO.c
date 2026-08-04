#include <stdio.h>

int main() {
    int album, comprou;
    int diferente = 0, repetido;
    int i, j;

    scanf("%d", &album);
    scanf("%d", &comprou);

    int numFi[comprou];

    for (i = 0; i < comprou; i++) {
        scanf("%d", &numFi[i]);
    }

    for (i = 0; i < comprou; i++) {
        repetido = 0;

        for (j = 0; j < i; j++) {
            if (numFi[i] == numFi[j]) {
                repetido = 1;
                break;
            }
        }

        if (repetido == 0) {
            diferente++;
        }
    }

    int faltam = album - diferente;
    printf("%d\n", faltam);

    return 0;
}