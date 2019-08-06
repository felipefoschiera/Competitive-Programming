#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int adj[101][101];

int main(){
    int t; 
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n, m, u, v;
        cin >> n >> m;
        memset(adj, INF, sizeof adj);
        for(int i = 0; i < n; i++) adj[i][i] = 0;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            adj[u][v] = adj[v][u] = 1;
        }
        int s, d; cin >> s >> d;
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                
        int res = 0;
        for(int i = 0; i < n; i++){
            if(adj[s][i] != INF && adj[i][d] != INF){
                res = max(res, adj[s][i]+adj[i][d]);
            }
        }
        cout << "Case " << tc << ": " << res << "\n";
    }
    return 0;
}