#include <stdio.h>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int>> aresta;

class UnionFind {
private:
    vector<int> p, rank;
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }
    bool isSameSet(int i, int j) { 
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { 
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) { 
                p[y] = x; 
            }else{ 
                p[x] = y; 
                if (rank[x] == rank[y]) rank[y]++;
            }
        } 
    }
};

int kruskal(int N, vector<aresta> &arestas){
    UnionFind uf(N);
    int custo = 0;
    for(auto e : arestas){
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            custo += e.first;
        }
    }
    return custo;
}