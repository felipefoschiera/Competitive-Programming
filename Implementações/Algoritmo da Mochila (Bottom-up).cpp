#include <stdio.h>
#include <string.h>
#include <vector>
#define MAX 112
using namespace std;
typedef vector<int> vi;


// Implementação com uso de memoria O(W)

int ks[MAX], ks2[MAX];
int knapsack(int W, int wt[], int v[], int n){
    memset(ks, 0, sizeof ks); 
    memset(ks2, 0, sizeof ks2);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++)
            if(j - wt[i-1] >= 0)
                ks2[j] = max(ks[j], ks[j-wt[i-1]] + v[i-1]);
        for(int j = 1; j <= W; j++)
            ks[j] = ks2[j];
    }
    return ks[W];
}

// Memoria O(nW)
int knapsack(int W, vi wt, vi v, int n){
    int ks[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0) ks[i][w] = 0;
            else if(wt[i-1] > w){
                ks[i][w] = ks[i-1][w];
            }else{
                ks[i][w] = max(v[i-1] + ks[i-1][w-wt[i-1]], ks[i-1][w]);
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

