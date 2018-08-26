#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> aresta;

class UnionFind {
private:
    vector<int> p, rank, setSize;
    int numSets;
public:
    UnionFind(int N){
        p.assign(N+1, 0);
        setSize.assign(N+1, 1);
        rank.assign(N+1, 0);
        numSets = N;
        for(int i = 0; i <= N; i++) p[i] = i;
    }
    int findSet(int x){ return (p[x] == x ? x : p[x] = findSet(p[x])); }
    bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            numSets--;
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x; setSize[x] += setSize[y];
            }else{
                p[x] = y; setSize[y] += setSize[x];
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)];}
};

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int kruskal(vector<aresta> arestas, int n){
    int cost = 0;
    UnionFind uf(n);
    for(auto e : arestas){
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            cost += e.first;
        }
    }
    return cost;
}


int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, K;
        scanf("%d %d", &N, &K);
        ii pontos[N];
        vector<aresta> arestas;
        for(int i = 0; i < N; i++)
            scanf("%d %d", &pontos[i].first, &pontos[i].second);
        for(int i = 0; i < N; i++)
            for(int j = i + 1; j < N; j++){
                // numero de pontos entre uma reta do ponto A ao ponto B = gcd(abs(x1-x2), abs(y1-y2)) - 1
                int calc = gcd(abs(pontos[i].first - pontos[j].first), abs(pontos[i].second - pontos[j].second));
                calc--;
                arestas.push_back(aresta(calc, ii(i, j)));
            }
        sort(arestas.begin(), arestas.end());
        int ans = kruskal(arestas, N) * K;
        printf("%d\n", ans);
    }

    return 0;
}