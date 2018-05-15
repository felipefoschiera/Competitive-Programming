#include <iostream>
#include <queue>
#include <vector>
#define INFTO ((int)1e9)

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int C, V;
vector<vii> LG;
vi dist;

void dijkstra(int s){
    dist.assign(C, INFTO);
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
        // for(int i = 0; i < (int)LG[u].size(); i++){
        //     int v = LG[u][i].first;
        //     int w = LG[u][i].second;
        //     if(dist[v] > dist[u] + w){
        //         dist[v] = dist[u] + w;
        //         Q.push(ii(dist[v], v));
        //     }
        // }
    }
}

int main(){
    cin >> C >> V;
    int u, v, w, i;
    LG.assign(C, vii());
    for(i = 0; i < V; i++){
        cin >> u >> v >> w;
        u--; v--;
        LG[u].push_back(ii(v, w));
        LG[v].push_back(ii(u, w));
    }
    dijkstra(0);
    if(dist[C-1] != INFTO){
        cout << dist[C-1] << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}