#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> aresta;
vector<int> pai;

int findSet(int a){
    return (pai[a] == a) ? a : pai[a] = findSet(pai[a]);
}

bool isSameSet(int a, int b){
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b){
    pai[findSet(a)] = findSet(b);
}

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

int main(){
    int V, A;
    scanf("%d %d", &V, &A);
    pai.assign(V, 0);
    for(int i = 0; i < V; i++) pai[i] = i;
    int u, v, w;
    vector<aresta> arestas;
    for(int i = 0; i < A; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        arestas.push_back(aresta(w, ii(u, v)));
    }
    sort(arestas.begin(), arestas.end());
    int res = kruskal(arestas);
    printf("%d\n", res);
}