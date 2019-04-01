#include <iostream>
#include <queue>
#include <cstring>
#include <bitset>
using namespace std;

#define INF 1e9
#define MAX_V 112

int res[MAX_V][MAX_V], mf, f, s, t;
vector<vector<int>> adj;
vector<int> p;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void EdmondKarp() {
	mf = 0;
	while (1) {
		f = 0;
		bitset<MAX_V> visited;
		visited.set(s);
		queue<int> q; q.push(s);
		p.assign(MAX_V, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
            for(auto v : adj[u]){
				if (res[u][v] > 0 && !visited.test(v)) {
					visited.set(v); q.push(v); p[v] = u;
				}
			}
		}
		augment(t, INF);
		if (f == 0)
			break;
		mf += f;
	}
}

int idCamiseta(string tamanho){
    if(tamanho == "XXL") return 0;
    if(tamanho == "XL") return 1;
    if(tamanho == "L") return 2;
    if(tamanho == "M") return 3;
    if(tamanho == "S") return 4;
    return 5;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(res, 0, sizeof res);
        adj.assign(MAX_V, vector<int>());
        int N, M;
        cin >> N >> M;
        s = 6+M+1;
        t = s+1;
        int cada = N / 6;
        for(int i = 0; i < M; i++){
            // source -> pessoa
            res[s][i] = 1;
            adj[s].push_back(i);
            adj[i].push_back(s);
            string a, b;
            cin >> a >> b;
            // pessoa -> camiseta
            int idA = idCamiseta(a)+M, idB = idCamiseta(b)+M;
            res[i][idA] = 1, res[i][idB] = 1;
            adj[i].push_back(idA);
            adj[i].push_back(idB);
            adj[idA].push_back(i);
            adj[idB].push_back(i);
        }
        // camiseta -> sink
        for(int i = 0; i < 6; i++){
            res[i+M][t] = cada;
            adj[i+M].push_back(t);
            adj[t].push_back(i+M);
        }
        EdmondKarp();
        cout << (mf >= M ? "YES" : "NO") << '\n';        
        }
        
    return 0;
}
