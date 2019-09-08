#include <bits/stdc++.h>
using namespace std;

int adj[112][112];

const int INF = 0x3f3f3f3f;

void floydWarshall(int n){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)	
					adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
}                          

int main(){
	int n, m, tc = 1;
	while(cin >> n >> m, n+m){
		int u, v, w;
		memset(adj, INF, sizeof adj);

		for(int i = 0; i <= n; i++){
			adj[i][i] = 0;
		}
		for(int i = 0; i < m; i++){
			cin >> u >> v >> w;
			adj[u][v] = w;
			adj[v][u] = w;
		}
		floydWarshall(n);
		
		for(int i = 0; i <= n; i++){
			adj[i][i] = 0;
		}
		int q;
		cin >> q;
		cout << "Instancia "<< tc++ << '\n';
		while(q--){
			cin >> u >> v;
			cout << min(adj[u][v], adj[v][u]) << '\n';
		}
		cout << '\n';
	}
	return 0;
}