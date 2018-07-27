#include <stdio.h>
#include <vector>
#define MAX 31234
using namespace std;
typedef long long ll;

vector<vector<int> > LG;

ll f[MAX], g[MAX];

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    LG.assign(MAX, vector<int>());
    for(int i = 0; i < M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        LG[u].push_back(v);
    }
    f[N] = g[N] = 1LL;
    for(int i = N-1; i > 0; i--){
        for(int j = 0; j < (int)LG[i].size(); j++){
            f[i] += f[LG[i][j]];
            g[i] = max(g[LG[i][j]], g[i]);
        }
        g[i] += f[i];
    }
    printf("%lld\n", g[1]);
    return 0;
}