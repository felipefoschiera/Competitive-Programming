#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int MAX = 1010;
vector<ii> adj[MAX];
int dist[MAX], n, m;

bool bellmanford(int s){
    memset(&dist, 1<<20, sizeof dist);
    dist[s] = 0;
    bool hasNegativeWeightCycle = false;
    for(int i = 0, v, w; i < n; i++){
        for(int u = 0; u < n; u++){
            for(int j = 0; j < (int)adj[u].size(); j++){
                v = adj[u][j].first;
                w = adj[u][j].second;
                if(i == n-1 && dist[v] > dist[u] + w)
                    hasNegativeWeightCycle = true;
                    else dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }
    return hasNegativeWeightCycle;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < MAX; i++) adj[i].clear();
        int u, v, w;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }
        bool res = bellmanford(0);
        cout << (res ? "possible" : "not possible") << '\n';
    }
    return 0;
}