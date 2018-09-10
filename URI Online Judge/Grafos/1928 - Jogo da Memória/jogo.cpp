#include <cstdio>
#include <vector>
using namespace std;
#define MAXN 51234
#define MAXLOGN 20

int comp(int a, int b) { return a + b; }

typedef pair<int, int> ii;

vector<int> adjList[MAXN];
int level[MAXN], N;
int P[MAXN][MAXLOGN];
int D[MAXN][MAXLOGN];

void depthdfs(int u) {
    for(auto v : adjList[u]){
		if (v == P[u][0]) continue;
		P[v][0] = u; D[v][0] = 1;
		level[v] = 1 + level[u];
		depthdfs(v);
	}
}

void computeP(int root) {
	level[root] = 0;
	P[root][0] = root; D[root][0] = 0;
	depthdfs(root);
	for(int j = 1; j < MAXLOGN; j++)
		for(int i = 1; i <= N; i++) {
			P[i][j] = P[P[i][j-1]][j-1];
			D[i][j] = comp(D[P[i][j-1]][j-1], D[i][j-1]);
		}
}

int LCA(int u, int v) {
	
	if (level[u] > level[v]) swap(u, v);
	int d = level[v] - level[u];
	int ans = 0;
	for(int i = 0; i < MAXLOGN; i++) {
		if (d & (1<<i)) {
			ans = comp(ans, D[v][i]);
			v = P[v][i];
		}
	}
	if (u == v) return ans;
	for(int i = MAXLOGN-1; i >= 0; i--)
		while(P[u][i] != P[v][i]) {
			ans = comp(ans, D[v][i]);
			ans = comp(ans, D[u][i]);
			u = P[u][i]; v = P[v][i];
		}

	ans = comp(ans, D[v][0]);
	ans = comp(ans, D[u][0]);
	return ans;
}

int main(){
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i <= N; i++) adjList[i].clear();
        int rel[N][2], x;
		for(int i = 0; i < N; i++) rel[i][0] = rel[i][1] = -1;
        for(int i = 1; i <= N; i++){
            scanf("%d", &x);
            if(rel[x][0] == -1) rel[x][0] = i;
            else rel[x][1] = i;
        }
        int a, b;
        for(int i = 0; i < N-1; i++){
            scanf("%d %d", &a, &b);
            adjList[a].push_back(b), adjList[b].push_back(a);
        }
        computeP(1);
        int res = 0;
        for(int i = 1; i <= N/2; i++){
            int u = rel[i][0], v = rel[i][1];
			res += LCA(u, v);
        }
        printf("%d\n", res);

    }
    return 0;
}