#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int adj[101][101];

int main(){
    int a, b, tc = 1;
    while(cin >> a >> b, a+b){
        memset(adj, INF, sizeof adj);
        int u, v;
        adj[a][b] = 1;
        while(cin >> u >> v, u+v){
            adj[u][v] = 1;
        }
        for(int k = 1; k <= 100; k++)
            for(int i = 1; i <= 100; i++)
                for(int j = 1; j <= 100; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                
        
        int soma = 0, count = 0;
        for(int i = 1; i <= 100; i ++){
            for(int j = 1; j <= 100; j++){
                if(i != j && adj[i][j] != INF){
                    count++;
                    soma += adj[i][j];
                }
            }
        }
        double res = soma / (double)count;
        cout << "Case " << tc++ << ": average length between pages = " << fixed << setprecision(3) << res << " clicks\n";
    }
    return 0;
}