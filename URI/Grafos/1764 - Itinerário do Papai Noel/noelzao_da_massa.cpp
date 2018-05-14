/**
 *  URI 1764 - Itinerário do Papai Noel
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
int M, N;
vector<vii> LG;
vector<bool> visited;

ll prim(int s){
    ll cost = 0;
    visited.assign(M, false);
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
    while(scanf("%d %d", &M, &N)){
        if(M == 0 && N == 0) break;
        int i, u, v, w;
        LG.assign(M, vii());    
        for(i = 0; i < N; i++){
            scanf("%d %d %d", &u, &v, &w);
            LG[u].push_back(ii(v, w));
            LG[v].push_back(ii(u, w));
        }
        ll ans = prim(0);
        printf("%lld\n", ans);
    }
    return 0;
}