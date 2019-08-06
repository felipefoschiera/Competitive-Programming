#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<int, pair<int, int>> aresta;

class UnionFind {
private:
    vector<int> p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        numSets = N; rank.assign(N, 0);
        p.assign(N, 0); for(int i = 0; i < N; i++) p[i] = i; }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { 
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) { 
                p[y] = x; 
            }else { 
                p[x] = y; 
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }   
};

pair<int, int> kruskal(vector<aresta> &arestas, int n){
    sort(arestas.begin(), arestas.end());
    vector<aresta> onmst;
    int cost1 = 0;
    UnionFind uf(n);
    for(int i = 0; i < arestas.size(); i++){
        aresta e = arestas[i];
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            cost1 += e.first;
            onmst.push_back(e);
        }
    }
    int cost2 = 1e9;
    for(auto e: onmst){
        UnionFind uf2(n);
        int costtest = 0, cnt = 0;
        for(auto x : arestas){
            if(x != e){
                if(!uf2.isSameSet(x.second.first, x.second.second)){
                    uf2.unionSet(x.second.first, x.second.second);
                    cnt++;
                    costtest += x.first;
                }
            }
        }
        if(cnt == n-1)
            cost2 = min(cost2, costtest);
    }

    return {cost1, cost2};
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        vector<aresta> arestas;
        cin >> n >> m;
        int u, v, w;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            u--, v--;
            arestas.push_back({w, {u, v}});
        }
        pair<int, int> res = kruskal(arestas, n);
        cout << res.first << " "<< res.second << "\n";
    }
    return 0;
}