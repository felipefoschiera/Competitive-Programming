#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ii;


const int MAX = 10101;
const int INF = 1e9;
int N, M;

vector<ii> adj[MAX];
vector<int> dist;

void dijkstra(int s){
    dist.assign(N, INF);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push({0, s});
    while(!Q.empty()){
        int u = Q.top().second;
        int d = Q.top().first;
        Q.pop();
        if(d > dist[u]) continue;
        for(auto e : adj[u]){
            int v = e.first, w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
            }
        }
    }
}