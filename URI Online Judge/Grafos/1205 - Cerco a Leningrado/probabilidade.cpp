// URI 1205 - Cerco a Leningrado
// Felipe G. Foschiera
#include <cstdio>
#include <cmath>
#include <queue>
#define INF ((int)1e9)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

int N, M, K;
vector<vi> LG;
vi dist, soldados;

void dijkstra(int s){
    dist.assign(N+1, INF);
    dist[s] = soldados[s];
    priority_queue<ii, vector<ii>, greater<ii> > Q;
    Q.push(ii(soldados[s], s));
    while(!Q.empty()){
        int u = Q.top().second; Q.pop();
        for(auto v : LG[u]){
            if(dist[v] > dist[u] + soldados[v]){
                dist[v] = dist[u] + soldados[v];
                Q.push(ii(dist[v], v));
            }
        }
    }
}

int main(){
    double P, prob;
    while(scanf("%d %d %d %lf", &N, &M, &K, &P) != EOF){
        LG.assign(N+1, vi());
        soldados.assign(N+1, 0);
        int u, v, A, pos, orig, dest;
        for(int i = 0; i < M; i++){
            scanf("%d %d", &u, &v);
            LG[--u].push_back(--v);
            LG[v].push_back(u);
        }
        scanf("%d", &A);
        for(int i = 0; i < A; i++){
            scanf("%d", &pos);
            soldados[--pos]++;
        }
        scanf("%d %d", &orig, &dest);
        dijkstra(--orig);
        int soldiers = dist[--dest];
        prob = (soldiers > K) ? 0.0 : pow(P, soldiers);
        printf("%.3lf\n", prob);

    }

    return 0;
}