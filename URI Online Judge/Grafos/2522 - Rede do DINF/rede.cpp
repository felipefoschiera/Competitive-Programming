/**
 *  URI 2522 - Rede do DINF
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, ii> dii;

double distance(ii a, ii b){
    return hypot(a.first-b.first, a.second-b.second);
}

vector<int> pai;

int findSet(int x){
    return (pai[x] == x) ? x : pai[x] = findSet(pai[x]);
}

bool isSameSet(int a, int b){
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b){
    pai[findSet(a)] = findSet(b);
}

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        vector<ii> pontos;
        vector<dii> arestas;
        int a, b;
        pai.assign(N, 0);
        for(int i = 0; i < N; i++){
            pai[i] = i;
            scanf("%d %d", &a, &b);
            pontos.push_back(ii(a, b));
        }
        for(int i = 0; i < N; i++){
            ii pa = pontos[i];
            for(int j = 0; j < i; j++){
                ii pb = pontos[j];
                double dist = distance(pa, pb);
                arestas.push_back(dii(dist, ii(i, j)));
            }
        }
        double total = 0.0;
        sort(arestas.begin(), arestas.end());
        for(auto e : arestas){
            if(!isSameSet(e.second.first, e.second.second)){
                unionSet(e.second.first, e.second.second);
                total += e.first;
            }
        }  
        printf("%.2lf\n", total);
        arestas.clear();
        pai.clear();
        pontos.clear();  
    }
    return 0;
}