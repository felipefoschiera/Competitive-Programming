#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;

int knapsack(int W, vi wt, vi v, int n){
    int ks[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0) ks[i][w] = 0;
            else if(wt[i-1] > w) ks[i][w] = ks[i-1][w];
            else ks[i][w] = max(ks[i-1][w], v[i-1] + ks[i-1][w-wt[i-1]]);
        }
    }
    return ks[n][W];
}


int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        vi pesos, valores;
        int v, p;
        for(int i = 0; i < N; i++){
            scanf("%d %d", &v, &p);
            valores.push_back(v);
            pesos.push_back(p);
            
        }
        int K, R; 
        scanf("%d %d", &K, &R);
        int ans = knapsack(K, pesos, valores, N);
        printf(ans >= R ? "Missao completada com sucesso\n" : "Falha na missao\n");
    }
    return 0;   
}