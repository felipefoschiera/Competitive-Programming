// URI 2910 / Maratona SBC 2018 - Highway Decommission
// Felipe G. Foschiera
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 10101;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> aresta;

vector<aresta> adj[MAXN];
ll dist[MAXN], minCost[MAXN];

ll dijkstra(int s, int N){
	memset(dist, INF, sizeof dist);
	memset(minCost, INF, sizeof minCost);
	dist[s] = minCost[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({0, s});
	while(!pq.empty()){
		int u = pq.top().second; pq.pop();
		for(auto e : adj[u]){
			int v = e.first;
			ll len = e.second.first, cost = e.second.second;
			if(dist[u] + len < dist[v]){
				dist[v] = dist[u] + len;
				minCost[v] = cost;
				pq.push({dist[v], v});
			}else if(dist[u] + len == dist[v]){
				if(cost < minCost[v]) minCost[v] = cost;
			}
		}
	}
	ll sum = 0;
	for(int i = 0; i < N; i++)
		sum += minCost[i];
	return sum;
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	int u, v;
	ll l, c;
	while(M--){
		scanf("%d %d %lld %lld", &u, &v, &l, &c);
		u--, v--;
		adj[u].push_back({v, {l, c}});
		adj[v].push_back({u, {l, c}});
	}
	printf("%lld\n", dijkstra(0, N));
	return 0;
}