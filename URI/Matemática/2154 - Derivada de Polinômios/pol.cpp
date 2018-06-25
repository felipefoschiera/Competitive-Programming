/**
 *  URI 2154 - Derivada de Polinômios
 *  Felipe G. Foschiera
 */
#include <stdio.h>

int main(){
    int T;
    while(scanf("%d", &T) != EOF){
        for(int i = 0; i < T; i++){
            int a, b;
            char c;
            scanf("%d%c%d", &a, &c, &b);
         
            if(b-1 <= 1)
                printf("%dx", a*b);
            else 
                printf("%dx%d", a*b, b-1);
             if(i != T-1){
                char d;
                scanf(" %c ", &d);
                printf(" + ");
            }else{
                printf("\n");
            }
        }
    }
    return 0;
}