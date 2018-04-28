#include <stdio.h>

int main() {
    int X, Y, M;
    while(scanf("%d %d %d", &X, &Y, &M) != EOF){
        while(M--){
            int xi, yi;
            scanf("%d %d", &xi, &yi);
            if((xi <= X && yi <= Y) || (xi <= Y && yi <= X)){
                printf("Sim\n");
            }else{
                printf("Nao\n");
            }
        }
    }
    return 0;
}