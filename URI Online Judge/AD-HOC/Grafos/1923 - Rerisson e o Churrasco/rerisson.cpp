#include <iostream>
#include <map>
#include <queue>
#define INF ((int)1e9)
using namespace std;

map<string, vector<string> > adj;
map<string, int> dist;

string nome = "Rerisson";

void bfs(){
    queue<string> fila;
    dist[nome] = 0;
    fila.push(nome);
    while(!fila.empty()){
        string u = fila.front();
        fila.pop();
        for(auto e : adj[u]){
            if(dist[e] > dist[u] + 1){
                dist[e] = dist[u] + 1;
                fila.push(e);
            }
        }
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, G;
    while(cin >> N >> G){
        string a, b;
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            adj[a].push_back(b), adj[b].push_back(a);
            dist[a] = INF, dist[b] = INF;
        }
        bfs();
        int cnt = 0;
        for(auto p : dist)
            if(p.first != nome && p.second <= G) cnt++;
        cout << cnt << '\n';
        for(auto p : dist)
            if(p.first != nome && p.second <= G) cout << p.first << '\n';
        adj.clear(), dist.clear();
        
    }
    return 0;
}