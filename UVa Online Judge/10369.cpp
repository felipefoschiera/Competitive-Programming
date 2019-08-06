#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int x[512], y[512];

double dist(int i, int j){
    return hypot(x[i]-x[j], y[i]-y[j]);
}

typedef pair<double, pair<int, int>> aresta;

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

double kruskal(vector<aresta> &arestas, int p, int s){
    sort(arestas.begin(), arestas.end());
    double cost = 0.0;
    UnionFind uf(p);
    for(auto e : arestas){
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            if(uf.numDisjointSets() == s) cost = e.first;
        }
    }
    return cost;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int s, p;
        cin >> s >> p;
        
        for(int i = 0; i < p; i++){
            cin >> x[i] >> y[i];
        }
        vector<aresta> arestas;
        for(int i = 0; i < p; i++){
            for(int j = i+1; j < p; j++){
                arestas.push_back({dist(i, j), {i, j}});
            }
        }
        cout << fixed << setprecision(2) << kruskal(arestas, p, s) << "\n";
    }
    return 0;
}