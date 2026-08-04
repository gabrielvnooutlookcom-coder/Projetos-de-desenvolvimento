#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	
	
	while(scanf("%d", &n) != EOF){
		int soma = 0;
		
		char *num = (char*)malloc((n + 1) * sizeof(char));
		scanf("%s",num);
		
		for(int i = 0; i < n; i++){
			soma += num[i] - '0';
		}
		
		if(soma % 3 == 0){
			printf("%d sim\n",soma);
		}else{
			printf("%d nao\n",soma);
		}
		
		free(num);
	}
	return 0;
}