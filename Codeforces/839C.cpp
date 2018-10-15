#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 101010;

vector<int> adj[MAXN];

double res = 0.0;

void dfs(int u, int p, double prob, int tam){
    bool filho = false;

    if(adj[u].size() > 1){
        if(p == -1) prob /= adj[u].size();
        else prob /= (adj[u].size()) - 1;
    }
    if(adj[u].size() > 1 || (adj[u].size() == 1 && p == -1)) filho = true;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u, prob, tam+1);
        }
    }
    if(!filho) res += prob * tam;
    
}

int main(){
    int n;
    scanf("%d", &n);
    int u, v;
    for(int i = 1; i < n; i++){
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, 1.0, 0);
    printf("%.15lf\n", res);
    return 0;
}