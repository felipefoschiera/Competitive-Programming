#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> aresta;

class UnionFind {
private:
    vector<int> p, rank;
public:
    UnionFind(int N){
        p.assign(N+1, 0);
        rank.assign(N+1, 0);
        for(int i = 0; i <= N; i++) p[i] = i;
    }
    int findSet(int i){
        return (p[i] == i ? i : p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int kruskal(vector<aresta> arestas, int N){
    UnionFind uf(N);
    int soma = 0;
    for(auto e : arestas){
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            soma += e.first;
        }
    }
    return soma;
}

int main(){
    int N, M;
    while(scanf("%d %d", &N, &M), (N+M)){
        vector<aresta> arestas;
        int u, v, w, soma = 0; 
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            arestas.push_back(aresta(w, ii(u, v)));
            soma += w;
        }
        sort(arestas.begin(), arestas.end());
        int ans = soma - kruskal(arestas, N);
        printf("%d\n", ans);
    }
    return 0;
}