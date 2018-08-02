#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;

int knapsack(int W, vi wt, vi v, int n){
    int ks[n+1][W+1];
    for(int i = 0; i < n; i++){
        for(int w = 0; w < W; w++){
            if(i == 0 || w == 0) ks[i][w] = 0;
            else if(wt[i-1] > w){
                ks[i][w] = ks[i-1][w];
            }else{
                ks[i][w] = min(v[i-1] + ks[i-1][w-wt[i-1]], ks[i-1][w]);
            }
        }
    }
    int res = ks[n][W];
    // Soma dos pesos:
    int soma_pesos = 0;
    int w = W;
    for(int i = n; i > 0; i--){
        if(res <= 0) break;
        if(res == ks[i-1][w]) continue;
        soma_pesos += wt[i-1];
        res -= v[i-1];
        w -= wt[i-1];
    }
}