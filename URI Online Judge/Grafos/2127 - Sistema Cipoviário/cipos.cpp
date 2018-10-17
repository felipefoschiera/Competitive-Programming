#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int> > aresta;

class UnionFind {
private:
    vector<int> p, rank;
public:
    UnionFind(int N){
        p.assign(N+1, 0);
        rank.assign(N+1, 0);
        for(int i = 0; i < N; i++) p[i] = i;
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

int kruskal(vector<aresta> &arestas, int &n){
    int cost = 0;
    UnionFind uf(n);
    for(auto e : arestas){
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            cost += e.first;
        }
    }
    return cost;
}

int main(){
    int N, M, TC = 1;
    while(scanf("%d %d", &N, &M) != EOF){
        vector<aresta> arestas;
        int u, v, w;
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            arestas.push_back({w, {u, v}});
        } 
        sort(arestas.begin(), arestas.end());
        printf("Instancia %d\n", TC++);
        printf("%d\n\n", kruskal(arestas, N));
    }
    return 0;
}