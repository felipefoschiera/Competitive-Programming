/**
 *  URI 2376 - Copa do Mundo
 *  Felipe G. Foschiera
 */
#include <stdio.h>

int main(){
    int game[8];
    int a, b;
    for(int i = 0; i < 8; i++){
        scanf("%d %d", &a, &b);
        game[i] = (a > b ? i*2 : i*2+1);
    }
    for(int i = 0; i < 4; i++){
        scanf("%d %d", &a, &b);
        game[i] = (a > b ? game[i*2] : game[i*2+1]);
    }
    for(int i = 0; i < 2; i++){
        scanf("%d %d", &a, &b);
        game[i] = (a > b ? game[i*2] : game[i*2+1]);
    }
    scanf("%d %d", &a, &b);
    printf("%c\n", (a > b) ? ('A' + game[0]) : ('A' + game[1]));
    return 0;   
}