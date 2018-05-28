#include <stdio.h>
#include <queue>
#include <algorithm>
#define INFINITO ((int)1e9)
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi dist;
vector<vii> adj;

void dijkstra(int s, int N)
{
    dist.assign(N, INFINITO);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(0, s));
    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        for (auto vizinho : adj[u])
        {
            int v = vizinho.first;
            int custo = vizinho.second;
            if (dist[v] > dist[u] + custo)
            {
                dist[v] = dist[u] + custo;
                Q.push(ii(dist[v], v));
            }
        }
    }
}

int main()
{
    int N, M, C, K;
    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N + M + C + K))
    {
        adj.assign(N, vii());
        int u, v, p;
        for (int i = 0; i < M; i++)
        {
            scanf("%d %d %d", &u, &v, &p);
            if ((u > C-1 && v > C-1) || (u < C && v < C && abs(u - v) == 1))
            {
                adj[u].push_back(ii(v, p));
                adj[v].push_back(ii(u, p));
            }
            if(u > C-1 && v < C){
                adj[u].push_back(ii(v, p));
            }
            if(v > C-1 && u < C){
                adj[v].push_back(ii(u, p));
            }
        }
        dijkstra(K, N);
        printf("%d\n", dist[C - 1]);
    }
    return 0;
}
