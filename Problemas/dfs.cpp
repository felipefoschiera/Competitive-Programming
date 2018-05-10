#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

queue<int> fila;

int main(){
    int N, T, V, A, i, x, y; scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &N, &V, &A);
        bool visitados[V];
        vector<int> adj[V];
        memset(visitados, 0, sizeof(visitados));
        int count = -1;
        for(i = 0; i < A; i++){ 
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        // DFS
        fila.push(N);
        visitados[N] = true;
        
        while(!fila.empty()){
            int frontEl = fila.front();
            int viz = adj[frontEl].size();
            for(i = 0; i < viz; i++){
                int v = adj[frontEl][i];
                if(!visitados[v]){
                    visitados[v] = true;
                    fila.push(v);
                    count++;
                }
            }
            count++;
            fila.pop();
         }
         printf("%d\n", count);
    }
    return 0;
}