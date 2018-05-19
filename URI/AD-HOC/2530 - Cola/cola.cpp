/**
 *  URI 2530 - Cola
 * Felipe G. Foschiera
 */ 
#include <stdio.h>

int isSubsequence(int n, int m, int juan[], int ricardo[]){
    int c = 0;
    for(int i = 0; i < n; i++)
        if(juan[i] == ricardo[c])
            c++;
    return c == m;
}

int main(){
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF){
        int juan[N], ricardo[M];
        for(int i = 0; i < N; i++)
            scanf("%d", juan+i);
        for(int i = 0; i < M; i++)
            scanf("%d", ricardo+i);
        printf(isSubsequence(N, M, juan, ricardo) ? "sim\n" : "nao\n");
    }
    return 0;
}