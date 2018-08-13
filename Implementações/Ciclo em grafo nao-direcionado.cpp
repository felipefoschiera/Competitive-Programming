#include <stdio.h>
#include <vector>
using namespace std;


typedef pair<int, int> aresta;

bool hasCycle(vector<aresta> arestas, int N){
    UnionFind uf(N);
    for(auto e : arestas){
        if(uf.isSameSet(e.first, e.second)){
            return true;
        }else{
            uf.unionSet(e.first,e .second);
        }
    }
    return false;
}