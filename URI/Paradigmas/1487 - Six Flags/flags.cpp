#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int knapsack(int W, vi wg, vi val, int n){
    int ks[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0)ks[i][w] = 0;
            else if(wg[i-1] <= w) ks[i][w] = max(val[i-1] + ks[i][w-wg[i-1]], ks[i-1][w]);
            else ks[i][w] = ks[i-1][w];
        }
    }
    return ks[n][W];
}

int main() {
    ios_base::sync_with_stdio(false);
    int instancia = 1;
    while(1){
        int N, T;
        cin >> N >> T;
        if(N == 0 && T == 0) break;
        vi tempos;
        vi pontos;
        for(int i = 0; i < N; i++){
            int d, p;
            cin >> d >> p;
            tempos.push_back(d);
            pontos.push_back(p);
        }
        int ans = knapsack(T, tempos, pontos, N);
        cout << "Instancia " << instancia << endl;
        cout << ans << endl;
        instancia++;
        cout << endl;
    }
    return 0;
}