#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
#define MAX 1123
using namespace std;

typedef pair<int, int> ii;
int adj[MAX][MAX];
int dist[MAX];

int M, N, G, K;

void dijkstra(int u){
	memset(dist, INF, sizeof dist);
	dist[u] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({0, u});
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(int i = 1; i <= N; i++){
			if(adj[u][i] < INF && dist[i] > dist[u] + adj[u][i]){
				dist[i] = dist[u] + adj[u][i];
				pq.push({dist[i], i});
			}
		}
	}
}

int main(){
	while(scanf("%d%d%d%d", &M, &N, &G, &K), (M+N+G+K)){
		int dano[M], mana[M];
		for(int i = 0; i < M; i++)
			scanf("%d %d", &mana[i], &dano[i]);
		int a, b;
		memset(adj, INF, sizeof adj);
		for(int i = 0; i < G; i++){
			scanf("%d %d", &a, &b);
			adj[a][b] = adj[b][a] = 0;
		}
		adj[0][1] = adj[1][0] = 0;
		int needmana[MAX];
		needmana[0] = 0;
		for(int i = 1; i < MAX; i++){
			needmana[i] = INF;
			for(int m = 0; m < M; m++){
				needmana[i] = min(needmana[i], mana[m] + 
								  needmana[i-dano[m] < 0 ? 0 : i-dano[m]]);
			}
		}
		int salao, vida;
		for(int i = 0; i < K; i++){
			scanf("%d %d", &salao, &vida);
			for(int i = 0; i <= N; i++)
				if(adj[i][salao] < INF)
					adj[i][salao] += needmana[vida];
		}
		dijkstra(0);
		printf("%d\n", dist[N] == INF ? -1 : dist[N]);

		
	}
	return 0;
}