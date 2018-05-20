/**
 *  URI 2359 - Alocando Ambulâncias
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <vector>
#include <queue>
#define INFTO ((int)1e9)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int N, M, Q;
vector<vii> LG;
vi dist;

void dijkstra(){
    dist.assign(N, INFTO);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int s;
    for(int i = 0; i < Q; i++){
        scanf("%d", &s);
        s--;
        dist[s] = 0;
        pq.push(ii(0, s));
    }
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        for(auto e : LG[u]){
            int v = e.first;
            int w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v));
            }
        }
    }

}

int main(){
    while(scanf("%d %d %d", &N, &M, &Q) != EOF){
        LG.assign(N, vii());
        int u, v, w;
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            LG[u].push_back(ii(v, w));
            LG[v].push_back(ii(u, w));
        }
        dijkstra();
        int max_dist = 0;
        for(int i = 0; i < N; i++){
            max_dist = max(max_dist, dist[i]);
        }
        printf("%d\n", max_dist);
    }
    return 0;
}