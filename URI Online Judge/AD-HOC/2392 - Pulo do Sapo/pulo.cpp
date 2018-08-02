/**
 *  URI 2392 - Pulo do Sapo
 *  Felipe G. Foschiera - UPF
 */
#include <stdio.h>
int pedras[101];

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int P, D;
        scanf("%d %d", &P, &D);
        pedras[--P] = 1;
        for(int j = P-D; j >= 0; j-= D) pedras[j] = 1;
        for(int j = P+D; j < N; j+= D) pedras[j] = 1; 
    }
    for(int i = 0; i < N; i++) printf("%d\n", pedras[i]);
    return 0;
}