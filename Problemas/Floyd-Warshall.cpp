#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX 512
#define INFTO 0x3f3f3f3f
using namespace std;

int AG[MAX][MAX];
int N, M;

void floydWarshall() {
    int i, j, k;
    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
}

int main() {
    int u, v, w, q, i;
    while (scanf("%d %d", &N, &M) && (N != 0))
    {
        memset(AG, INFTO, sizeof(AG));
        for (i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            AG[u][v] = w;
            if ((AG[u][v] != INFTO) && (AG[v][u] != INFTO))
                AG[u][v] = AG[v][u] = 0;
        }
        floydWarshall();
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d", &u, &v);
            u--, v--;
            if (AG[u][v] != INFTO)
                printf("%d\n", AG[u][v]);
            else
                printf("Nao e possivel entregar a carta\n");
        }
        printf("\n");
    }
    return 0;
}