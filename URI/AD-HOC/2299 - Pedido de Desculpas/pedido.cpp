// Felipe G. Foschiera
// URI 2299 - Pedido de Desculpas
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef vector<int> vi;

int knapsack(int W, vi wg, vi val, int n){
    int ks[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                ks[i][w] = 0;
            }else if(wg[i-1] <= w){
                ks[i][w] = max(val[i-1] + ks[i-1][w-wg[i-1]], ks[i-1][w]); 
            }else{
                ks[i][w] = ks[i-1][w];
            }
        }
    }
    return ks[n][W];
}

int main() {
    int t = 1;
    while(1){
        int C, F;
        cin >> C >> F;
        if(C == 0 && F == 0) break;
        vi vals;
        vi pesos;
        for(int i = 0; i < F; i++){
            int p, v;
            cin >> p >> v;
            vals.push_back(v);
            pesos.push_back(p);
        }
        cout << "Teste " << t << "\n";
        t++;
        cout << knapsack(C, pesos, vals, F) << "\n\n";
    }

 
    return 0;
}