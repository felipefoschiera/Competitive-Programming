#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 1010;

vector<int> adj[MAXN];
int friends[MAXN];
int rem[MAXN];

int main(){
    int n, m, k;
    while(scanf("%d %d %d", &n, &m, &k) != EOF){
        for(int i = 0; i < n; i++) adj[i].clear();
        memset(friends, 0, sizeof friends);
        memset(rem, 0, sizeof rem);
        int a, b;
        while(m--){
            scanf("%d %d", &a, &b);
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            friends[a]++, friends[b]++;
        }
        int cnt = n;
        queue<int> fila;
        for(int i = 0; i < n; i++){
            if(friends[i] < k){
                fila.push(i);
                rem[i] = 1;
                cnt--;
            }
        }
        while(!fila.empty()){
            int u = fila.front();
            fila.pop();
            for(auto v : adj[u]){
                if(!rem[v]){
                    friends[v]--;
                    if(friends[v] < k){
                        fila.push(v);
                        rem[v] = 1;
                        cnt--;
                    }
                }
            }
        }
        if(cnt > 0){
            for(int i = 0; i < n; i++){
                if(!rem[i]){
                    printf("%d%c", i+1, (--cnt == 0) ? '\n' : ' ');
                }
            }
        }else printf("0\n");
    }
    return 0;
}