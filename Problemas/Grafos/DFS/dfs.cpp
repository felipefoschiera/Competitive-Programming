#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
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
        printf("Visitando u = %d\n", u+1);
        for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                pilha.push(v);
                
            }
        }
    }

}

int main(){
    scanf("%d %d", &V, &A);
    adj.assign(V, vi());
    int i, u, v;
    for(i = 0; i < A; i++){
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    return 0;
}