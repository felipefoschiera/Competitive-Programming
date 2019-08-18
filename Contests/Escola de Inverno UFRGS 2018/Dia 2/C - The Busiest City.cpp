/*
 * ICPC Jakarta 2013 - The Busiest City
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int N;
vector<vi> LG;
vi stSize;

int dfs(int u, int par){
    stSize[u] = 1;
    for(int v : LG[u])
        if(v != par)
            stSize[u] += dfs(v, u);
    return stSize[u];
}

int solve(int u, int par){
    int paths = (N - stSize[u]) * (stSize[u] - 1);
    for(int v : LG[u])
        if(v != par)
            paths += stSize[v] * (N - stSize[v] - 1);
    paths /= 2;
    for(int v : LG[u])
        if(v != par)
            paths = max(paths, solve(v, u));
    return paths;
}

int main(){
    int T, tc, i, u, v;
    scanf("%d", &T);
    for(tc = 1; tc <= T; tc++){
        scanf("%d", &N);
        LG.assign(N, vi());
        for(i = 0; i < N-1; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            LG[u].push_back(v);
            LG[v].push_back(u);
        }
        stSize.assign(N, 0);
        dfs(0, 0);
        printf("Case #%d: %d\n", tc, solve(0, 0));
    }
    return 0;
}
