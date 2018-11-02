// Codeforces 466A - Cheap Travel
// Felipe G. Foschiera
#include <cstdio>
#include <cstring>
#define INF ((int)1e9)

const int MAX = 1123;

inline int min(int a, int b) { return a < b ? a : b; }

int dp[MAX];
int n, m, a, b;

int solve(int tickets){
    if(dp[tickets] != -1) return dp[tickets];
    if(tickets == 0) return 0;
    if(tickets < 0) return INF;
    return dp[tickets] = min(a + solve(tickets-1), b + solve(tickets-m));
}

int main(){
    scanf("%d %d %d %d", &n, &m, &a, &b);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(n));
    return 0;
}