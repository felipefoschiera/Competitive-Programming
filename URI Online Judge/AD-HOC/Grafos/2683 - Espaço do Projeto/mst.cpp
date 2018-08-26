/**
 *  URI 2683 - Espaço do Projeto
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> aresta;

vector<int> pai, _rank;

int findSet(int x){
    return (pai[x] == x) ? x : pai[x] = findSet(pai[x]);
}

bool isSameSet(int x, int y){
    return findSet(x) == findSet(y);
}

void unionSet(int x, int y){
    if(!isSameSet(x, y)){
        int a = findSet(x), b = findSet(y);
        if(_rank[a] > _rank[b]){
            pai[b] = a;
        }else{
            pai[a] = b;
            if(_rank[a] == _rank[b]){
                _rank[b]++;
            }
        }
    }
}

int kruskal(vector<aresta> arestas){
    int cost = 0;
    for(auto e : arestas){
        if(!isSameSet(e.second.first, e.second.second)){
            unionSet(e.second.first, e.second.second);
            cost += e.first;
        }
    }
    return cost;
}
int main(){
    int N;
    scanf("%d", &N);
    vector<aresta> arestas, arestasNeg;
    pai.assign(N, 0);
    _rank.assign(N, 0);
    int u, v, w;
    for(int i = 0; i < N; i++){
        pai[i] = i;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        arestas.push_back(aresta(w, ii(u, v)));
        arestasNeg.push_back(aresta(-w, ii(u, v)));
    }
    sort(arestas.begin(), arestas.end());
    sort(arestasNeg.begin(), arestasNeg.end());
    int maxCost = abs(kruskal(arestasNeg));
    for(int i = 0; i < N; i++) pai[i] = i;
    _rank.assign(N, 0);
    int minCost = kruskal(arestas);
    printf("%d\n%d\n", maxCost, minCost);
    return 0;
}