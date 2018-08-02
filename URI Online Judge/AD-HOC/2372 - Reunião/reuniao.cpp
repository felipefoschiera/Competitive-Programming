/**
 *  URI 2372 - Reunião
 *  Felipe G. Foschiera - UPF
 */
#include <stdio.h>
#include <string.h>
#define INFTO 0x3f3f3f3f
#define MAX 112

int N, AG[MAX][MAX];

inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}

void floydWarshall() {
    int i, j, k;
    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
            
}

int main(){
    int M;
    scanf("%d %d", &N, &M);
    memset(AG, INFTO, sizeof AG);
    int u, v, w;    
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &u, &v, &w);
        AG[u][v] = AG[v][u] = w;
        AG[u][u] = AG[v][v] = 0;        
    }
    floydWarshall();
    int best = INFTO;
    for(int i = 0; i < N; i++){
        int maximo = 0;
        for(int j = 0; j < N; j++){
            maximo = max(maximo, AG[j][i]);
        }
        best = min(best, maximo);
    }
    printf("%d\n", best);

    return 0;
}