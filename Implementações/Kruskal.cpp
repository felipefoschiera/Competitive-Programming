#include <stdio.h>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> aresta;
 

// Utilizar Union-Find
// Ordenar o vetor de arestas

int kruskal(vector<aresta> arestas){
    int custo = 0;
    for(auto e : arestas){
        if(!isSameSet(e.second.first, e.second.second)){
            unionSet(e.second.first, e.second.second);
            custo += e.first;
        }
    }
    return custo;
}