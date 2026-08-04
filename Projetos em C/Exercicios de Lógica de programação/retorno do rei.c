//retrorno do rei
#include <stdio.h>

int main(){
	int N, G, i;
	scanf("%d %d", &N, &G);
	
	int valores[26] = {0};
	
	for (i = 0; i < N; i++){
		char r;
		int v;
		scanf(" %c %d", &r, &v);
		valores[r - 'A'] = v;
	}
	
	int X;
	scanf("%d", &X);
	
	int soma = 0;
	char c;
	
	for (i = 0; i < X; i++){
		scanf(" %c", &c);
		soma += valores[c - 'A'];
	}
	printf("%d\n", soma);
	
	if(soma >= G){
		 printf("You shall pass!\n");
    }else{
        printf("My precious\n");
    }

    return 0;
	
}