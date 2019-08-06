#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 101010;

vector<int> adj[MAX];

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) adj[i].clear();
        int u, v, w;
        for(int i = 0; i < n-1; i++){
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(w);
            adj[v].push_back(w);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            if(adj[i].size() >= 2){
                sort(adj[i].begin(), adj[i].end());
                for(int j = 1; j < adj[i].size(); j++)
                    ans += adj[i][0] + adj[i][j];
            }
        }
        printf("%lld\n",ans);
  }
}