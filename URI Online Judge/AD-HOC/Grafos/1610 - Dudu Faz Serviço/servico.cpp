/**
 *  URI 1610 - Dudu Faz Serviço
 */
#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;

vi visited;
vector<vi> LG;
bool cycle = false;

void dfs(int s){
    visited[s] = 1;
    if(cycle) return;
    for(auto v : LG[s]){
        if(visited[v] == 1){
            cycle = true; return;
        }else if(!visited[v]) dfs(v);
    }
    visited[s] = 2;
}

int main(){
    int T, n, m;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &m);
        int u, v;
        LG.assign(n, vi());
        visited.assign(n, 0);
        cycle = false;
        for(int i = 0; i < m; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            LG[u].push_back(v);
        }
        for(int i = 0; i < n; i++){
            if(!visited[i])
                dfs(i);
            if(cycle) break;
        }
        printf(cycle ? "SIM\n" : "NAO\n");
    }
    return 0;
}