#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> LG;
vector<int> tax;

int N, C;

int dfs(int u, int p){
    int res = 0;
    for(auto e : LG[u]){
        int v = e.first, w = e.second;
        if(v == p) continue;
        res += dfs(v, u);
        int travel = (tax[v] + C - 1) / C;
        res += travel * 2 * w;
        tax[u] += tax[v];
    }
    return res;
}

int main(){
    while(scanf("%d %d", &N, &C) != EOF){
        LG.assign(N+1, vii());
        tax.assign(N+1, 0);
        for(int i = 0; i < N; i++) scanf("%d", &tax[i]);
        int u, v, w;
        for(int i = 0; i < N-1; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            LG[u].push_back(ii(v, w));
            LG[v].push_back(ii(u, w));
        }
        int ans = dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}