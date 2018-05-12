#include <stdio.h>
#include <queue>
#include <vector>
#define INFTO ((int)1e9)
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int V, A;
vector<vii> LG;
vector<bool> visited;

int prim(int s){
    int cost = 0;
    visited.assign(V, false);
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(0, s));
    while(!Q.empty()){
        int u = Q.top().second;         
        int peso = Q.top().first;        
        Q.pop();
        if(!visited[u]){
            visited[u] = true;
            cost += peso;
            for(int i = 0; i < (int)LG[u].size(); i++){
                int v = LG[u][i].first;
                int w = LG[u][i].second;
                    Q.push(ii(w, v));
            }
        }
    }
    return cost;
}

int main(){ 
    while(scanf("%d %d", &V, &A) && (V != 0 && A != 0)){
        LG.assign(V, vii());
        int i, u, v, w, soma = 0;
        for(i = 0; i < A; i++){
            scanf("%d %d %d", &u, &v, &w);
            soma += w;
            LG[u].push_back(ii(v, w));
            LG[v].push_back(ii(u, w));
        }
        int pathCost = prim(0);
        printf("%d\n", soma - pathCost);
    }

    return 0;
}