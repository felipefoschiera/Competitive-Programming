// Codeforces 189A - Cut Ribbon
// Felipe G. Foschiera
#include <cstdio>
#include <cstring>
#define INF ((int)1e9)

inline int max(int a, int b) { return a > b ? a : b; }
const int MAX = 4123;

int dp[MAX];
int n, a, b, c;

int solve(int pc){
    if(dp[pc] != -1) return dp[pc];
    if(pc == 0) return 0;
    int res = -INF;
    if(pc-a >= 0) res = max(res, 1 + solve(pc-a));
    if(pc-b >= 0) res = max(res, 1 + solve(pc-b));
    if(pc-c >= 0) res = max(res, 1 + solve(pc-c));
    return dp[pc] = res;
}


int main(){
    while(scanf("%d %d %d %d", &n, &a, &b, &c) != EOF){
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(n));
    }
    return 0;
}