#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#define INF ((int)1e9)
using namespace std;
typedef vector<int> vi;


unordered_map<string, int> pos;
vector<vi> adj;
vi dist;

int bfs(int pt, int start, int end){
    dist.assign(pt+1, INF);
    dist[start] = 0;
    queue<int> fila;
    fila.push(start);

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        for(auto v : adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                fila.push(v);
            }
        }
    }
    return dist[end];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int pt, lig;
    string a, b;
    while(cin >> pt >> lig){
        adj.assign(pt+1, vi());
        int idx = 0;
        while(lig--){
            cin >> a >> b;
            if(pos.find(a) == pos.end()) pos[a] = idx++;
            if(pos.find(b) == pos.end()) pos[b] = idx++;
            adj[pos[a]].push_back(pos[b]);
            adj[pos[b]].push_back(pos[a]);
        }
        int start = pos["Entrada"], saida = pos["Saida"], queijo = pos["*"];
        printf("%d\n", bfs(pt, start, queijo) + bfs(pt, queijo, saida));
        pos.clear();
        
    }
    return 0;
}