#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define UNVISITED -1

map<string, int> id;
string nomes[40];

vector<int> adj[40];

int dfsNumberCounter, numSCC;
vector<int> dfs_num, dfs_low, S, visited;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = 1;
    for(auto v : adj[u]){
        if(dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        numSCC++;
        while(1){
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            cout << nomes[v];
            if(u == v){
                cout << "\n";
                break;
            }else cout << ", ";
        }
    }
}

int main(){
    int n, m, tc = 1;
    bool first = 1;
    while(cin >> n >> m, n+m){
        if(!first) cout << "\n";
        else first = 0;
        string u, v;
        id.clear();
        for(int i = 0; i < 40; i++) adj[i].clear();

        dfs_num.assign(n+1, UNVISITED);
        dfs_low.assign(n+1, 0);
        visited.assign(n+1, 0);
        dfsNumberCounter = numSCC = 0;
        int idCounter = 0;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            if(id.find(u) == id.end()){
                id[u] = idCounter;
                nomes[idCounter++] = u;
            }
            if(id.find(v) == id.end()){
                id[v] = idCounter;
                nomes[idCounter++] = v;
            }
            adj[id[u]].push_back(id[v]);
        }
        cout << "Calling circles for data set " << tc++ << ":\n";
        for(int i = 0; i < n; i++){
            if(dfs_num[i] == UNVISITED)
                tarjanSCC(i);
        }
    }
    return 0;
}