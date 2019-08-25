#include <bits/stdc++.h>
using namespace std;

const int MAX = 300;

typedef pair<int, int> ii;
typedef long long ll;

vector<ii> adj[MAX];
vector<int> dist;

ll dijkstra(int s, int end, int N){
    dist.assign(N+1, 1e9);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().second; 
        int d = pq.top().first;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto e : adj[u]){
            int v = e.first, w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[end];
}

int main(){
    int n, m, c, k;
    while(cin >> n >> m >> c >> k, n+m+c+k){
        for(int i = 0; i <= n; i++) adj[i].clear();
        int u, v, w;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            if(u < c && v < c && abs(u-v) == 1){
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
                

            }else if(u >= c && v >= c){
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }else if(u < c && v >= c){
                adj[v].push_back({u, w});
            }else if(v < c && u >= c){
                adj[u].push_back({v, w});
            }
        }
        ll res = dijkstra(k, c-1, n);
        cout << res << '\n';
        
    }
    return 0;
}