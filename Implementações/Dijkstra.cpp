#include <iostream>
#include <queue>
#include <vector>
#define INF ((int)1e9)

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, M;
vector<vii> LG;
vi dist;

void dijkstra(int s){
    dist.assign(N, INF);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(0, s));
    while(!Q.empty()){
        int u = Q.top().second; Q.pop();
        for(auto e : LG[u]){
            int v = e.first, w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push(ii(dist[v], v));
            }
        }
    }
}