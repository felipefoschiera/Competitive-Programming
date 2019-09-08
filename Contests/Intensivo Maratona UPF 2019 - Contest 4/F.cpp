#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

typedef pair<int, pair<int, int>> aresta;

const int MAX = 212340;
const int MAXLOGN = 16;

vector<ii> adj[MAX];

int level[MAX], N;
int P[MAX][MAXLOGN], D[MAX][MAXLOGN];

void depthdfs(int u){
	for(auto e : adj[u]){
		int v = e.first, w = e.second;
		if(v == P[u][0]) continue;
		P[v][0] = u; D[v][0] = w;
		level[v] = 1 + level[u];
		depthdfs(v);
	}
}

void computeP(int root){
	memset(level, 0, sizeof level);
	memset(P, 0, sizeof P);
	memset(D, 0, sizeof D);
	level[root] = 0;
	P[root][0] = root;
	D[root][0] = 0;
	depthdfs(root);
	for(int j = 1; j < MAXLOGN; j++){
		for(int i = 1; i <= N; i++){
			P[i][j] = P[P[i][j-1]][j-1];
			D[i][j] = min(D[P[i][j-1]][j-1], D[i][j-1]);
		}
	}
}

int LCA_Min(int u, int v){
	if(level[u] > level[v]) swap(u, v);
	int d = level[v] - level[u];
	int ans = 1e9;
	for(int i = 0; i < MAXLOGN; i++){
		if(d & (1 << i)){
			ans = min(ans, D[v][i]);
			v = P[v][i];
		}
	}
	if(u == v) return ans;
	for(int i = MAXLOGN-1; i >= 0; i--){
		while(P[u][i] != P[v][i]){
			ans = min(ans, D[v][i]);
			ans = min(ans, D[u][i]);
			u = P[u][i];
			v = P[v][i];
		}
	}
	ans = min(ans, D[v][0]);
	ans = min(ans, D[u][0]);
	return ans;
}

class UnionFind {
private:
	vector<int> parent, rank;
public:
	UnionFind(int N){
		rank.assign(N+1, 0);
		parent.assign(N+1, 0);
		for(int i = 0; i <= N; i++) parent[i] = i;
	}
	int findSet(int i){
		return (i == parent[i] ? i : findSet(parent[i]));
		return i;
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if(isSameSet(i, j)) return;
		int x = findSet(i), y = findSet(j);
		if(rank[x] > rank[y]) parent[y] = x;
		else {
			parent[x] = y;
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
};


void kruskal(vector<aresta> &edges){
	UnionFind uf(N+1);
	for(auto e : edges){
		int u = e.second.first, v = e.second.second;
		int w = e.first;
		if(!uf.isSameSet(u, v)){
			uf.unionSet(u, v);
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, s;
	while(cin >> N >> m >> s){
		vector<aresta> edges;
		for(int i = 0; i <= N; i++) adj[i].clear();
		int u, v, w;
		for(int i = 0; i < m; i++){
			cin >> u >> v >> w;
			edges.push_back({w, {u, v}});
		}
		sort(edges.rbegin(), edges.rend());
		kruskal(edges);
		computeP(1);
		while(s--){
			cin >> u >> v;
			cout << LCA_Min(u, v) << '\n';
		}

	}
	return 0;
}