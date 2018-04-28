#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#define INF ((int)1e9)
using namespace std;
typedef vector<int> vi;

int knapsack(int W, vi wt, vi val, int n){
    int ks[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0){
                ks[i][w] = (w == 0) ? 0 : -INF;
            }
            if(w == 0){
                ks[i][w] = 0;
            }
            if(i != 0 && w != 0){
            if(wt[i-1] <= w){
                ks[i][w] = max(val[i-1] + ks[i][w - wt[i-1]], ks[i-1][w]);

            }else{
                ks[i][w] = ks[i-1][w];
            }
        }
    }
    }
    int res = ks[n][W];
    cout << res << "\n";
}

int main() {

    int N, M;
    while(cin >> N >> M){
        vi pesos;
        vi vals;
        for(int i = 0; i < N; i++){
            int p, v;
            cin >> p >> v;
            pesos.push_back(p);
            vals.push_back(v);
        }
        knapsack(M, pesos, vals, N);
        
    }

    return 0;
}