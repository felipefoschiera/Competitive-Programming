#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[112];

vector<int> ts, dfs_num;
void dfs(int u){
    dfs_num[u] = 1;
    for(auto v : adj[u]){
        if(dfs_num[v] == -1)
            dfs(v);
    }
    ts.push_back(u);
}


int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        ts.clear();
        for(int i = 1; i <= n; i++) adj[i].clear();
        dfs_num.assign(n+1, -1);
        int u, v;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for(int i = 1; i <= n; i++)
            if(dfs_num[i] == -1)
                dfs(i);

        for(int i = ts.size()-1; i >= 0; i--){
            cout << ts[i] << (i == 0 ? "\n" : " ");
        }
    }
    return 0;
}