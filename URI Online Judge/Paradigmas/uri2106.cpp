#include <cstdio>
#include <cstring>
#define INF ((int)1e9)
#define MAX 18

inline int min(int a, int b) { return a < b ? a : b; }
int n, dp[1 << MAX], cost[MAX][MAX];


int solve(int bitmask, int done){
    if(dp[bitmask] != -1) return dp[bitmask];
    int best = INF;
    for(int i = 0; i < n; i++)
        if(!(bitmask & (1 << i)))
            best = min(best, solve(bitmask | (1<<i), done+1) + cost[done][i]);
    return dp[bitmask] = best;
}

int main(){
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &cost[i][j]);
        memset(dp, -1, sizeof dp);
        dp[(1<<n)-1] = 0;
        printf("%d\n", solve(0, 0));
    }
    return 0;
}