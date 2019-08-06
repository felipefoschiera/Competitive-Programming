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
    int findSet(int x) { return p[x] == x ? x : p[x] = findSet(p[x]); }
    bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }
    void unionSet(int x, int y){
        if(!isSameSet(x, y)){
            int i = findSet(x), j = findSet(y);
            if(rank[i] > rank[j]){
                p[j] = i;
            }else{
                p[i] = j;
                if(rank[i] == rank[j]) rank[j]++;
            }
        }
    }
};

int kruskal(vector<aresta> arestas, int n){
    UnionFind uf(n);
    int cost = 0;
    for(auto e : arestas){
        if(!(uf.isSameSet(e.second.first, e.second.second))){
            uf.unionSet(e.second.first, e.second.second);
            cost += e.first;
        }
    }
    return cost;
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m), (n+m)){
        vector<aresta> arestas(m);
        int u, v, w, soma = 0;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &w);
            arestas[i] = aresta(w, ii(u, v));
            soma += w;
        }
        sort(arestas.begin(), arestas.end());
        printf("%d\n", soma - kruskal(arestas, n));

    }
    return 0;
}