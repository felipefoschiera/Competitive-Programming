#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;

vi v, w;
vector<vi> ks;

int knapsack(int i, int m){
    if(ks[i][m] != -1) return ks[i][m];
    if(i == 1 && w[i] <= m) return ks[i][m] = v[i];
    if(i == 1 || m == 0) return ks[i][m] = 0;
    if(w[i] > m) return ks[i][m] = knapsack(i-1, m);
    return ks[i][m] = max(knapsack(i-1, m), knapsack(i-1, m - w[i]) + v[i]);
}


int main(){
    int W, N, teste = 1;
    while(scanf("%d %d", &W, &N) && (W+N)){
        v.reserve(N+1), w.reserve(W+1);
        for(int i = 1; i <= N; i++){
            scanf("%d", &w[i]);
            scanf("%d", &v[i]);
        }
        ks.assign(N+1, vi(W+1, -1));
        printf("Teste %d\n", teste++);
        printf("%d\n\n", knapsack(N, W));
    }

    return 0;
}