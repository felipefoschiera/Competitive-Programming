#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 212345
#define MAXLOGN 20
#define INF 0x3f3f3f3f

typedef long long ll;

ll comp(ll a, ll b) { return a + b; }

typedef pair<int, ll> ii;

vector<ii> adjList[MAXN];
int level[MAXN], N;
int P[MAXN][MAXLOGN];
ll D[MAXN][MAXLOGN];

void depthdfs(int u) {
    for(auto i : adjList[u]){
		int v = i.first;
        ll w = i.second;
		if (v == P[u][0]) continue;
		P[v][0] = u; D[v][0] = w;
		level[v] = 1 + level[u];
		depthdfs(v);
	}
}

void computeP(int root) {
	level[root] = 0;
	P[root][0] = root; D[root][0] = 0;
	depthdfs(root);
	for(int j = 1; j < MAXLOGN; j++)
		for(int i = 0; i < N; i++) {
			P[i][j] = P[P[i][j-1]][j-1];
			D[i][j] = comp(D[P[i][j-1]][j-1], D[i][j-1]);
		}
}

ii LCA(int u, int v) {
	if (level[u] > level[v]) swap(u, v);
	int d = level[v] - level[u];
	ll ans = 0;
	for(int i = 0; i < MAXLOGN; i++) {
		if (d & (1<<i)) {
			ans = comp(ans, D[v][i]);
			v = P[v][i];
		}
	}
	if (u == v) return ii(u, ans);
	for(int i = MAXLOGN-1; i >= 0; i--)
		while(P[u][i] != P[v][i]) {
			ans = comp(ans, D[v][i]);
			ans = comp(ans, D[u][i]);
			u = P[u][i]; v = P[v][i];
		}
	ans = comp(ans, D[v][0]);
	ans = comp(ans, D[u][0]);
	return ii(P[u][0], ans);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    while(cin >> N, N){
		for(int i = 0; i < N; i++) adjList[i].clear();
        int v;
        ll w;
        for(int u = 1; u < N; u++){
            cin >> v >> w;
			adjList[u].push_back({v, w});
			adjList[v].push_back({u, w});            
        }
        computeP(0);
        int Q, s, t;
        cin >> Q;
        while(Q--){
            cin >> s >> t;
            cout << (LCA(s, t).second) << (Q == 0 ? '\n' : ' ');
        }
    }
    return 0;
}