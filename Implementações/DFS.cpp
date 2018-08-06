#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
typedef vector<int> vi;

stack<int> pilha;

int V, A;

vector<bool> vis;
vector<vi> adj;

void dfs(int s){
    vis.assign(V, false);
    vis[s] = true;
    pilha.push(s);
    while(!pilha.empty()){
        int u = pilha.top(); pilha.pop();
        for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                pilha.push(v); 
            }
        }
    }
}

void dfsRecursiva(int u){
    vis[u] = 1;
    for(auto e : adj[u]){
        if(!vis[e]) dfs(e);
    }
}

int main(){
    for(int i = 0; i < V; i++)
        if(!vis[i]) dfs(i);
    return 0;
}