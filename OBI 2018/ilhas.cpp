#include <stdio.h>
#include <queue>
#include <algorithm>
#define INFTO ((int)1e9)
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, M;
vector<vii> LG;
vi dist;

void dijkstra(int s){
	dist.assign(N, INFTO);
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	Q.push(ii(0, s));
	while(!Q.empty()){
		int u = Q.top().second; Q.pop();
		for(auto e : LG[u]){
			int v = e.first;
			int w = e.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				Q.push(ii(dist[v], v));
			}
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	LG.assign(N, vii());
	int u, v, w;
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &u, &v, &w);
		u--, v--;
		LG[u].push_back(ii(v, w));
		LG[v].push_back(ii(u, w));
	}
	int s;
	scanf("%d", &s);
	s--;
	dijkstra(s);
	sort(dist.begin(), dist.end());
	int menor = -1;
	int maior = 0;
	for(int i = 0; i < N; i++){
		if(menor == -1 && dist[i] != 0) menor = dist[i];
		if(dist[i] > maior) maior = dist[i];
	}
	printf("%d\n", maior-menor);

	return 0;
}