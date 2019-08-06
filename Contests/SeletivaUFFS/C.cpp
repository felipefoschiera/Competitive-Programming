#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int MOD = 1000000007;
string s, t;
int n, m;

int dp[110][101010];

int solve(int a, int b){
    if(a == n) return 1;
    if(b == m) return 0;
    if(dp[a][b] != -1)
        return dp[a][b];
    int res = 0;
    if(s[a] == t[b]){
        res = ((solve(a+1, b+1) % MOD) + (solve(a, b+1) % MOD)) % MOD;
    }else{
        res = solve(a, b+1) % MOD;
    }
    return dp[a][b] = res;
}

int main(){
    cin >> s >> t;
    n = s.size();
    m = t.size();
    memset(dp, -1, sizeof dp);
    cout << (solve(0, 0) % MOD) << '\n';
    return 0;
}