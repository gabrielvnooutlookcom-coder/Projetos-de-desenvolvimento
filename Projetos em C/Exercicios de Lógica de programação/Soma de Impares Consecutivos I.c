//somas de imapares consectivos
#include <stdio.h>
 
int main() {
 
    int x,y,impares = 0;
    
    scanf("%d\n",&x);
    scanf("%d\n",&y);
    
    if(x > y){
        for(int i = x - 1; i > y; i--){
            if(i % 2 != 0){
                impares += i;
            }
        }
    }else if(x < y){
        for (int i = x + 1; i < y; i++){
            if(i % 2 != 0){
                impares += i;
            }
        }
    }else if(x == y){
        impares = 0;
    }
    
    printf("%d\n",impares);
     
 
    return 0;
}