#include <stdio.h>

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    int *p;
    int i, aux;
    int n = 5;

    p = v;

    for (i = 0; i < n / 2; i++) {
        aux = *(p + i);
        *(p + i) = *(p + n - 1 - i);
        *(p + n - 1 - i) = aux;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}