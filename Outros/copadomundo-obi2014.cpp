/**
 *  URI 2459 - Copa do Mundo / OBI 2014 - Fase 1 - Nível 2
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <vector> 
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> aresta;
vector<int> pai;

int findSet(int x){
    return (pai[x] == x) ? x : pai[x] = findSet(pai[x]);
}

bool isSameSet(int x, int y){
    return findSet(x) == findSet(y);
}

void unionSet(int x, int y){
    pai[findSet(x)] = findSet(y);
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
    int N, F, R;
    scanf("%d %d %d", &N, &F, &R);
    int a, b, c;
    pai.assign(N, 0);
    vector<aresta> arestas;
    for(int i = 0; i < N; i++) pai[i] = i;
    for(int i = 0; i < F+R; i++){
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        arestas.push_back(aresta(c, ii(a, b)));
    }
    sort(arestas.begin(), arestas.begin() + F);
    sort(arestas.begin() + F, arestas.end());
    int ans = kruskal(arestas);
    printf("%d\n", ans);

    return 0;
}