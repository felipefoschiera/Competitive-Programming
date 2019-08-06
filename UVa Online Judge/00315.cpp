#include <iostream>
#include <sstream>
#include <vector>
#define UNVISITED -1
using namespace std;

const int MAX = 110;

vector<int> adj[MAX];
vector<int> dfs_low, dfs_num, dfs_parent, articulation_vertex;
int dfsNumberCounter, rootChildren, dfsRoot;

void articulationPointsAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(auto v : adj[u]){
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            if(u == dfsRoot) rootChildren++;

            articulationPointsAndBridge(v);
            if(dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = true;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);                
        }else if(v != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(){
    int n;
    while(cin >> n, n){
        for(int i = 1; i <= n; i++) adj[i].clear();
        dfsNumberCounter = 0; dfs_num.assign(n+1, UNVISITED);
        dfs_low.assign(n+1, 0); dfs_parent.assign(n+1, 0); articulation_vertex.assign(n+1, 0);
        string s;
        while(getline(cin, s), s != "0"){
            stringstream ss(s);
            int x, v;
            ss >> x;
            while(ss >> v){
                adj[x].push_back(v);
                adj[v].push_back(x);
            }
        }
        for(int i = 1; i <= n; i++){
            if(dfs_num[i] == UNVISITED){
                dfsRoot = i; rootChildren = 0; articulationPointsAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > i);
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++)
            if(articulation_vertex[i]) res++;
        cout << res << '\n';
    }
    return 0;
}