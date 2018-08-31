#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 55
#define UNVISITED -1
using namespace std;

int C, P, bridgeCount, dfsNumberCounter;
vector<vector<int> > adj;
vector<int> dfs_parent, dfs_num, dfs_low;

void articulationPointAndbridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(auto v : adj[u]){
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            articulationPointAndbridge(v);
            if(dfs_low[v] > dfs_num[u]) bridgeCount++;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }else if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main(){
    while(scanf("%d %d", &C, &P) != EOF){
        dfsNumberCounter = 0, bridgeCount = 0;
        dfs_num.assign(C, UNVISITED);
        dfs_low.assign(C, 0);
        dfs_parent.assign(C, 0);
        adj.assign(C, vector<int>());
        int u, v;
        for(int i = 0; i < P; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        articulationPointAndbridge(0);
        printf("%d\n", bridgeCount);
    }
    return 0;
}
