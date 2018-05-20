/**
 *  URI 2550 - Novo Campus
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

int kruskal(vector<aresta> arestas, int N){
    int cost = 0;
    for(auto e : arestas){
        if(!isSameSet(e.second.first, e.second.second)){
            unionSet(e.second.first, e.second.second);
            cost += e.first;
        }
    }
    for(int i = 0; i < N; i++){
        if(!isSameSet(i, 0)){
            return -1;
        }
    }
    return cost;
}

int main(){
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF){
        pai.assign(N, 0);
        for(int i = 0; i < N; i++) pai[i] = i;
        vector<aresta> arestas;
        int a, b, c;
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &a, &b, &c);
            a--, b--;
            arestas.push_back(aresta(c, ii(a, b)));
        }
        sort(arestas.begin(), arestas.end());
        int cost = kruskal(arestas, N);
        if(cost != -1){
            printf("%d\n", cost);
        }else{
            printf("impossivel\n");
        }
    }
    return 0;
}