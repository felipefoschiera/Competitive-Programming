/**
 *  URI 2173 - Caixa Dois
 *  Felipe G. Foschieras
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ii> aresta;

vector<int> pai;
vector<int> _rank;

int findSet(int x){
    return (pai[x] == x) ? x : pai[x] = findSet(pai[x]);
}

bool isSameSet(int x, int y){
    return findSet(x) == findSet(y);
}

void unionSet(int x, int y){
    if(!isSameSet(x, y)){
        int a = findSet(x), b = findSet(y);
        if(_rank[a] > _rank[b]) pai[b] = a;
        else{
            pai[a] = b;
            if(_rank[a] == _rank[b])  _rank[b]++;
        }
    }
}

int kruskal(vector<aresta> arestas){
    ll cost = 0;
    for(auto e : arestas){
        if(!isSameSet(e.second.first, e.second.second)){
            unionSet(e.second.first, e.second.second);
            cost += e.first;
        }
    }
    return cost;
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) && (n+m)){
        pai.assign(n, 0);
        _rank.assign(n, 0);
        vector<aresta> arestas;
        vector<aresta> arestasNeg;
        for(int i = 0; i < n; i++) pai[i] = i;
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            arestas.push_back(aresta(w, ii(u, v)));
            arestasNeg.push_back(aresta(-w, ii(u, v)));
        }
        sort(arestas.begin(), arestas.end());
        ll minCost = kruskal(arestas);
        _rank.assign(n, 0);        
        for(int i = 0; i < n; i++) pai[i] = i;
        sort(arestasNeg.begin(), arestasNeg.end());
        ll maxCost = abs(kruskal(arestasNeg));
        printf("%lld\n", maxCost - minCost);

                
    }
    return 0;
}
