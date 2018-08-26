#include <stdio.h>
#include <vector>
#define UNVISITED -1
using namespace std;
typedef vector<int> vi;

int N, M, dfsNumberCounter, numSCC;
vi num, low, S, visited;
vector<vi> LG;

void tarjanSCC(int u){
    low[u] = num[u] = dfsNumberCounter++; 
    S.push_back(u); 
    visited[u] = 1;
    for(auto v : LG[u]){
        if(num[v] == UNVISITED) tarjanSCC(v);
        if(visited[v]) low[u] = min(low[u] , low[v]);
    }
    if(low[u] == num[u]) { 
        numSCC++;
        while(1){
            int v = S.back(); S.pop_back(); visited[v] = 0;
            if(u == v) break;
        }
    }
}

int main(){
    while(scanf("%d %d", &N, &M), (N+M)){
        num.assign(N+1, UNVISITED);
        low.assign(N+1, 0);
        visited.assign(N+1, 0);
        LG.assign(N+1, vi());
        int u, v, t;
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &t);
            u--, v--;
            LG[u].push_back(v);
            if(t == 2) LG[v].push_back(u);
        }
        dfsNumberCounter = numSCC = 0;
        for(int i = 0; i < N; i++)
            if(num[i] == UNVISITED) tarjanSCC(i);
        printf("%d\n", (numSCC == 1));
    }
    return 0;
}