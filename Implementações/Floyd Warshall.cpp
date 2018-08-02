#include <stdio.h>
#include <algorithm>
#define MAX 112
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