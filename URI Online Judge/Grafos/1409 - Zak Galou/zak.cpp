#include <stdio.h>
#include <string.h>
#include <queue>
#define MAX 1024
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> ii;

int mana[MAX], dano[MAX], menor[MAX], M, N;
int adj[MAX][MAX], dist[MAX];

void dijkstra(){
	memset(dist, INF, sizeof dist);
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({0, 0});
	dist[0] = 0;
	while(!pq.empty()){
		int u = pq.top().second; pq.pop();
		for(int i = 1; i <= N; i++){
			if(adj[u][i] < INF && dist[i] > dist[u] + adj[u][i]){
				dist[i] = dist[u] + adj[u][i];
				pq.push({dist[i], i});
			}
		}
	}
}


int main(){
	int G, K;
	while(scanf("%d %d %d %d", &M, &N, &G, &K), (M+N+G+K)){
        for(int i = 0; i < M; i++)
			scanf("%d %d", &mana[i], &dano[i]);
		
		menor[0] = 0;
		for(int hp = 1; hp < MAX; hp++){
			menor[hp] = INF;
			for(int j = 0; j < M; j++){
				int restante = hp - dano[j] > 0 ? hp - dano[j] : 0;
				menor[hp] = min(menor[hp], menor[restante] + mana[j]);
			}
		}
		memset(adj, INF, sizeof adj);
		adj[0][1] = 0;
		int u, v;
		for(int i = 0; i < G; i++){
			scanf("%d %d", &u, &v);
			adj[u][v] = adj[v][u] = 0;
		}
		int salao, vida;
		while(K--){
			scanf("%d %d", &salao, &vida);
			for(int j = 0; j <= N; j++)
				if(adj[j][salao] < INF) adj[j][salao] += menor[vida];
		}
		dijkstra();
		printf("%d\n", dist[N] != INF ? dist[N] : -1);
	}
	return 0;
}