#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 101
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int AG[MAX][MAX][MAX];

void floydWarshall()
{
    int i, j, k, h;
    for (k = 0; k < MAX; k++)
        for (h = 0; h <= k; h++)
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    AG[k][i][j] = min(AG[k][i][j], AG[k][i][h] + AG[k][h][j]);
}

int main()
{
    while (scanf("%d %d", &N, &M) != EOF)
    {
        memset(AG, INF, sizeof(AG));
        int i, u, v, w, Q;
        while (M--)
        {
            scanf("%d %d %d", &u, &v, &w);
            u--;
            v--;
            for (i = 0; i < N; i++)
            {
                AG[i][u][v] = AG[i][v][u] = w;
                AG[i][u][u] = AG[i][v][v] = 0;            
            }
        }
        floydWarshall();
        scanf("%d", &Q);
        while (Q--)
        {
            scanf("%d %d %d", &u, &v, &w);
            u--;
            v--;
            w--;
            int ans = AG[w][u][v];
            printf("%d\n", (ans != INF ? ans : -1));
        }
    }
    return 0;
}