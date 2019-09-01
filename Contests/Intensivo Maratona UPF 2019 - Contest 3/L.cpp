#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 112;
typedef pair<int, int> ii;
typedef long long ll;

vector<ii> adjO[MAX], adjA[MAX];
vector<ll> dist;

ll dijkstra(int t, int &N){
    dist.assign(N+1, INF);
    dist[1] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto e : (t == 0 ? adjO[u] : adjA[u])){
            int v = e.first, w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[N];
}

int main(){
    int n, m;
    while(cin >> n >> m){
        for(int i = 0; i <= n; i++){
            adjO[i].clear(); adjA[i].clear();
        }
        int a, b, t, r;
        for(int i = 0; i < m; i++){
            cin >> a >> b >> t >> r;
            (t == 0 ? adjA[a] : adjO[a]).push_back({b, r});
        }
        ll res = min(dijkstra(0, n), dijkstra(1, n));
        cout << res << '\n';

    }
    return 0;
}