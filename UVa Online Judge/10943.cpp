#include <iostream>
#include <string.h>
using namespace std;

const int MOD = 1000000;
int n, k;
int dp[110][110];

int solve(int n, int k){
    if(k == 0) return n == 0;
    if(dp[n][k] != -1)
        return dp[n][k];
    int res = 0;
    for(int i = 0; i <= n; i++){
        res = ((res % MOD) + (solve(n-i, k-1) % MOD)) % MOD;
    }
    return dp[n][k] = res;
}

int main(){
    while(cin >> n >> k, n+k){
        memset(dp, -1, sizeof dp);
        cout << solve(n, k) << '\n'; 
    }
    return 0;
}