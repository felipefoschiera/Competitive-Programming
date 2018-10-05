#include <cstdio>
#include <queue>
#define MAXN 112
using namespace std;

int color[MAXN];
vector<int> adj[MAXN];

bool ehBipartido(int n){
    for(int i = 0; i < n; i++) color[i] = -1;
    int s = 0;
    queue<int> q;
    q.push(s);
    color[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }else if(color[v] == color[u]) return false;
        }
    }
    return true;
}

int main(){
    int n, m, inst = 1;
    while(scanf("%d %d", &n, &m) != EOF){
        int u, v;
        for(int i = 0; i < n; i++) adj[i].clear();
        while(m--){
            scanf("%d %d", &u, &v);
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        printf("Instancia %d\n", inst++);
        printf("%s\n", ehBipartido(n) ? "sim" : "nao");
        printf("\n");
    }
    return 0;
}