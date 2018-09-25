#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 212345
#define MAXLOGN 20

vector<int> adjList[MAXN];
int level[MAXN], N;
int P[MAXN][MAXLOGN];

void depthdfs(int u) {
    for(auto v : adjList[u]){
		if (v == P[u][0]) continue;
		P[v][0] = u;;
		level[v] = 1 + level[u];
		depthdfs(v);
	}
}

void computeP(int root) {
	level[root] = 0;
	P[root][0] = root; 
	depthdfs(root);
	for(int j = 1; j < MAXLOGN; j++)
		for(int i = 1; i <= N; i++) {
			P[i][j] = P[P[i][j-1]][j-1];
		}
}

int LCA(int u, int v) {
	if (level[u] > level[v]) swap(u, v);
	int d = level[v] - level[u];
	for(int i = 0; i < MAXLOGN; i++) {
		if (d & (1<<i)) {
			v = P[v][i];
		}
	}
	if (u == v) return u;
	for(int i = MAXLOGN-1; i >= 0; i--)
		while(P[u][i] != P[v][i]) {
			u = P[u][i]; v = P[v][i];
		}
	return P[u][0];
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d", &N);
        for(int i = 0; i <= N; i++) adjList[i].clear();
        int M, u;
        for(int i = 1; i <= N; i++){
            scanf("%d", &M);
            for(int j = 0; j < M; j++){
                scanf("%d", &u);
                adjList[i].push_back(u);
                adjList[u].push_back(i);
            }
        }
        computeP(1);
        int Q, v;
        scanf("%d", &Q);
        printf("Case %d:\n", t);
        while(Q--){
            scanf("%d %d", &u, &v);
            printf("%d\n", LCA(u, v));
        }

    }
    return 0;
}