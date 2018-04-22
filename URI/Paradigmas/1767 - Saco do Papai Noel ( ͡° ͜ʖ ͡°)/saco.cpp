#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

void knapsack(int W, vi wt, vi val, int n){
    int ks[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                ks[i][w] = 0;
            }else if(wt[i-1] <= w){
                ks[i][w] = max(val[i-1] + ks[i-1][w - wt[i-1]], ks[i-1][w]);

            }else{
                ks[i][w] = ks[i-1][w];
            }
        }
    }
    int res = ks[n][W];
    printf("%d brinquedos\n", res);
    int soma_pesos = 0, pacotes = 0;
    int w = W;
    for(int i = n; i > 0; i--){
        if(res <= 0){
            break;
        }
        if(res == ks[i-1][w]){
            continue;
        }else{
            soma_pesos += wt[i-1];
            pacotes++;
            res -= val[i-1];
            w -= wt[i-1];
        }
    }
    printf("Peso: %d kg\n", soma_pesos);
    printf("sobra(m) %d pacote(s)\n\n", n - pacotes);
    
}


int main() {
    int N;
    scanf("%d", &N);
    while(N--){
        int pac;
        scanf("%d", &pac);
        vi pesos;
        vi vals;
        for(int i = 0; i < pac; i++){
            int qt, p;
            scanf("%d %d", &qt, &p);
            pesos.push_back(p);
            vals.push_back(qt);
        }
        int W = 50;
        knapsack(W, pesos, vals, pac);
    }
   return 0;
}