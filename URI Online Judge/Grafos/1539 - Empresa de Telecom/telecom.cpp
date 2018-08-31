#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#define MAX 112
#define INF 0x3f3f3f3f
#define eps 1e-9
#define fs first
#define sc second
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii > antena;

double AG[MAX][MAX];
int N;

double distancia(antena a, antena b){
    return hypot(a.sc.fs-b.sc.fs, a.sc.sc-b.sc.sc);
}

void floydWarshall(){
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
}

int main(){
    while(scanf("%d", &N), N){
        vector<antena> antenas(N);
        int x, y, r;
        for(int i = 0; i < N; i++){
            scanf("%d %d %d", &x, &y, &r);
            antenas[i] = antena(r, ii(x, y));
        }
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                AG[i][j] = (i == j) ? 0 : INF;
            
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                    double d = distancia(antenas[i], antenas[j]);
                    if(d + eps <= antenas[i].first + eps)
                        AG[i][j] = d;
                }
        
        floydWarshall();
        int C, a, b;
        scanf("%d", &C);
        while(C--){
            scanf("%d %d", &a, &b);
            a--, b--;
            printf("%d\n", AG[a][b] != INF ? (int)AG[a][b] : -1);
        }
    }
    return 0;
}