#include <bits/stdc++.h>
using namespace std;

int mat[20][20];
const int INF = 1e9;
int pd[20][1<<20];

int solve(int linha, int mask){
    if(linha == 20){
        return 0;
    }
    if(pd[linha][mask] != -1)
        return pd[linha][mask];
    int res = 0;
    for(int j = 0; j < 20; j++){
        if(!(mask & (1 << j))){
            res = max(res, mat[linha][j] + solve(linha+1, mask | (1 << j)));
        }

    }
    return pd[linha][mask] = res;
}

int main(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            cin >> mat[i][j];
        }
    }
    memset(pd, -1, sizeof pd);
    int res = solve(0, 0);
    cout << res << '\n'; 
    return 0;
}