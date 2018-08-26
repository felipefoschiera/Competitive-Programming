/**
 * URI 1774 - Roteadores
 * Felipe G. Foschiera
 */
#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
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
            for(auto v : LG[u]){
                Q.push(ii(v.second, v.first));
            }
        }
    }
    return cost;
}

int main(){
    scanf("%d %d", &V, &A);
    int u, v, w;
    LG.assign(V, vii());
    for(int i = 0; i < A; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        LG[u].push_back(ii(v, w));
        LG[v].push_back(ii(u, w));
    }
    int ans = prim(0);
    printf("%d\n", ans);
    return 0;
}