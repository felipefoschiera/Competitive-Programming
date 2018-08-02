#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 
using namespace std;
typedef vector<int> vi;

int ans, N;
vector<vi> LG;

int dfs(int u, int pai){
    int peso = 1;
    for(int i = 0; i < (int)LG[u].size(); i++){
        int v = LG[u][i]; 
        if(v != pai)
            peso += dfs(v, u);   
    }
    int diff = abs(N - 2*peso); 
    ans = min(ans, diff);
    return peso;
}

int main(){
    int i, u, v;
    scanf("%d", &N);
    LG.assign(N+1, vi());    
    for(i = 0; i < N-1; i++){
        scanf("%d %d", &u, &v);
        LG[u].push_back(v);
        LG[v].push_back(u);
    }
    ans = N;
    dfs(1, -1);
    printf("%d\n", ans);

    return 0;
}