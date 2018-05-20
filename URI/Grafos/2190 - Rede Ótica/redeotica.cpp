/**
 *  URI 2190 - Rede Ótica
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

void kruskal(vector<aresta> arestas){
    for(auto a : arestas){
        if(!isSameSet(a.second.first, a.second.second)){
            unionSet(a.second.first, a.second.second);
            if(a.second.first > a.second.second){
                printf("%d %d\n", a.second.second+1, a.second.first+1);
            }else{
                printf("%d %d\n", a.second.first+1, a.second.second+1);
            }
        }
    }
}


int main(){
    int N, M;
    int teste = 1;
    while(scanf("%d %d", &N, &M) && (N != 0)){
        vector<aresta> arestas;
        int u, v, w;
        pai.assign(N, 0);
        for(int i = 0; i < N; i++) pai[i] = i;
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            arestas.push_back(aresta(w, ii(u, v)));
        }
        sort(arestas.begin(), arestas.end());
        printf("Teste %d\n", teste);
        teste++;
        kruskal(arestas);
        printf("\n");
    }
    return 0;
}