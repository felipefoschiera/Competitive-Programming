#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f3f

const int MAX = 112;

int AG[MAX][MAX];

inline int min(int a, int b) { return a < b ? a : b; }

void floydWarshall(int &N){
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
}

int main(){
    int N, R;
    while(scanf("%d %d", &N, &R), N+R){
        int u, v, w;
        memset(AG, INF, sizeof AG);
        while(R--){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            AG[u][v] = AG[v][u] = w;
        }
        floydWarshall(N);
        int minimo = INF;
        int cost[N];
        memset(cost, 0, sizeof cost);
        for(int i = 0; i < N; i++){
            for(int v = 0; v < N; v++){
                if(AG[i][v] != INF) cost[i] += AG[i][v];
            }
            if(cost[i] < minimo) minimo = cost[i];
        }
        for(int i = 0; i < N; i++){
            if(cost[i] <= minimo) printf("%d ", i+1);
        }
        printf("\n");
    }
    return 0;
}