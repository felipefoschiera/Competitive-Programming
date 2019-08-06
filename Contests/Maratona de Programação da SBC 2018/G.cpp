#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXV = 1123;

int A[MAXV]; // capacidade dos postos
int B[MAXV]; // capacidade das refinarias

typedef pair<int, pair<int, int> > edge;
typedef long long ll;

#define MAXN 21234
#define MAXM 51234

ll INF = 1e15;

edge edges[MAXN];

int ned, first[MAXN], work[MAXN];
ll cap[MAXM];
int to[MAXM], nxt[MAXM], dist[MAXM];

void init(){
	memset(first, -1, sizeof first);
	ned = 0;
}

void add(int u, int v, ll f){
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, ll f, int s, int t){
	if(u == t) return f;
	int v, df;
	for(int &e = work[u]; e != -1; e = nxt[e]){
		v = to[e];
		if(dist[v] == dist[u] + 1 && cap[e] > 0){
			df = dfs(v, min(f, cap[e]), s, t);
			if(df > 0){
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}

		}
	}
	return 0;
}

bool bfs(int s, int t){
	int u, v;
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	queue<int> q; q.push(s);
	while(!q.empty()){
		u = q.front(); q.pop();
		for(int e = first[u]; e != -1; e = nxt[e]){
			v = to[e];
			if(dist[v] < 0 && cap[e] > 0){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist[t] >= 0;
}

ll dinic(int s, int t){
	ll result = 0, f;
	while(bfs(s, t)){
		memcpy(work, first, sizeof work);
		while(f = dfs(s, INF, s, t)) result += f;
	}
	return result;
}




int p, r, c;
long long total = 0;

bool binarySearch(int k){
	int S = p+r, T = S+1;
	int N = p+r+2;
	init();
	for(int i = 0; i < p; i++)
		add(i, T, A[i]); // posto -> sink com capacidade do posto
	for(int i = 0; i < r; i++)
		add(S, p+i, B[i]); // source -> refinaria com capacidade de refinaria
	for(int i = 0; i <= k; i++)
		add(p+edges[i].second.second, edges[i].second.first, (ll)1e10);
	return dinic(S, T) == total;
}

int main(){
	scanf("%d %d %d", &p, &r, &c);
	for(int i = 0; i < p; i++){
		scanf("%d", &A[i]);
		total += A[i];
	}
	for(int i = 0; i < r; i++)
		scanf("%d", &B[i]);
	int u, v, w;
	for(int i = 0; i < c; i++){
		scanf("%d %d %d", &u, &v, &w);
		u--, v--;
		edges[i] = {w, {u, v}};
	}
	sort(edges, edges+c);
	int l = 0, r = c-1;
	int ans = -1;
	while(l <= r){
		int mid = (l+r)/2;
		if(binarySearch(mid)){
			ans = edges[mid].first;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	printf("%d\n", ans);
	return 0;
}