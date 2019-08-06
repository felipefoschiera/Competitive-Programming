#include <bits/stdc++.h>
using namespace std;

const int MAX = 212;
const int INF = 0x3f3f3f3f;

int risk[MAX], id[MAX];
int adj[MAX][MAX][MAX];

bool cmp(int a, int b){
  return risk[a] < risk[b];
}

int main(){
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; tc++){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
      id[i] = i;
      cin >> risk[i];
    }
    memset(adj, INF, sizeof adj);
    sort(id+1, id+n+1, cmp);
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        cin >> adj[0][i][j];
      }
    }
    for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
          adj[k][i][j] = min(adj[k-1][i][j], adj[k-1][i][id[k]] + adj[k-1][id[k]][j]);
    cout << "Case #" << tc << ":\n";  
    while(q--){
      int u, v, w;
      cin >> u >> v >> w;
      int x = 0;
      for(int i = 1; i <= n; i++)
        if(risk[id[i]] <= w)
          x = i;
      cout << adj[x][u][v] << '\n';
    }

  }
  return 0;
}