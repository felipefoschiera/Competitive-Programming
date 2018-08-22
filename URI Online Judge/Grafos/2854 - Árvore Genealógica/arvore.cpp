#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;

class UnionFind {
private:
    vi p, rank;
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
                p[y] = x;  }
            else { 
                p[x] = y; 
                if (rank[x] == rank[y]) rank[y]++; }
        } 
    }
    int numDisjointSets() { return numSets; }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    while(cin >> M >> N){
        map<string, int> id;
        UnionFind uf(M);
        string a, rel, b;
        int x = 0;
        for(int i = 0; i < N; i++){
            cin >> a >> rel >> b;
            if(id.find(a) == id.end()) id[a] = x++;
            if(id.find(b) == id.end()) id[b] = x++;
            uf.unionSet(id[a], id[b]);
        }
        cout << uf.numDisjointSets() << '\n';
    }
    return 0;
}