#include <iostream>
#include <vector>
using namespace std;


vector<int> adj[212];
vector<bool> visited;

void dfs(int u){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v]) dfs(v);
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<int> grau(n, 0);
        visited.assign(n, 1);
        int u, v;
        for(int i = 0; i < n; i++) adj[i].clear();
        while(m--){
            cin >> u >> v;
            grau[u]++;
            grau[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
            visited[u] = visited[v] = 0;
        }
        bool ok = true;
        for(int i = 0; i < n; i++)
            if(grau[i]%2==1) ok = false;
        if(!ok){
            cout << "Not Possible\n";
        }else{
            int comp = 0;
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    comp++; dfs(i);
                }
            }
            cout << (comp == 1 ? "Possible" : "Not Possible") << '\n';
        }
    }
    return 0;
}