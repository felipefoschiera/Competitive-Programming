/**
 *  URI 1476 - Caminhão
 *  Felipe G. Foschiera
 * 
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 21234
#define MAXLOGN 20
#define INF ((int)1e9)
using namespace std;


int N, M, S;
typedef pair<int, int> ii;
typedef pair<int, ii> aresta;

vector<ii> adj[MAXN];
int level[MAXN], P[MAXN][MAXLOGN];
int D[MAXN][MAXLOGN];

void depthdfs(int u){
    for(auto i : adj[u]){
        int v = i.first, w = i.second;
        if(v == P[u][0]) continue;
        P[v][0] = u; D[v][0] = w;
        level[v] = 1 + level[u];
        depthdfs(v);
    }
}

void computeP(int root) {
	level[root] = 0;
	P[root][0] = root; D[root][0] = 0LL;
	depthdfs(root);
	for(int j = 1; j < MAXLOGN; j++)
		for(int i = 1; i <= N; i++) {
			P[i][j] = P[P[i][j-1]][j-1];
			D[i][j] = min(D[P[i][j-1]][j-1], D[i][j-1]);
        }
}


int LCA_MenorAresta(int u, int v){
    if(level[u] > level[v]) swap(u, v);
    int d = level[v] - level[u];
    int ans = INF;
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
            u = P[u][i]; v = P[v][i];
        }
    }
	ans = min(ans, D[v][0]);
	ans = min(ans, D[u][0]);
    return ans;

}

class UnionFind {
private:
    vector<int> p, rank;
public:
    UnionFind(int N){
        p.assign(N+1, 0);
        rank.assign(N+1, 0);
        for(int i = 0; i <= N; i++) p[i] = i;
    }
    int findSet(int i) { return i == p[i] ? i : p[i] = findSet(p[i]); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

void kruskal(vector<aresta> &arestas, int N){
    sort(arestas.rbegin(), arestas.rend());
    UnionFind uf(N);
    for(auto e : arestas){
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            adj[e.second.first].push_back({e.second.second, e.first});
            adj[e.second.second].push_back({e.second.first, e.first});
        }
    }
}



int main(){
    while(scanf("%d %d %d", &N, &M, &S) != EOF){
        for(int i = 0; i <= N; i++) adj[i].clear();
        vector<aresta> arestas;
        int u, v, w;
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            arestas.push_back({w, {u, v}});
        }
        kruskal(arestas, N);
        computeP(1);
        int a, b;
        while(S--){
            scanf("%d %d", &a, &b);
            printf("%d\n", LCA_MenorAresta(a, b));
        }
    }

    return 0;
}