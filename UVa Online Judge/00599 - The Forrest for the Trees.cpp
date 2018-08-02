// UvA 00599 - The Forrest for the Trees
// Felipe G. Foschiera
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N){
        setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
        p.assign(N, 0); for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
            else { p[x] = y; setSize[y] += setSize[x]; 
                if(rank[x] == rank[y]) rank[y]++;
            } 
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
    int T;
    cin >> T;
    cin.ignore();
    while(T--){
        UnionFind uf(26);
        string s;
        while(getline(cin, s), s[0] != '*'){
            uf.unionSet(s[1] - 'A', s[3] - 'A');
        }
        getline(cin, s);
        int sz = s.length(), n = 0, acorns = 0;
        for(int i = 0; i < sz; i += 2){
            n++;
            if(uf.sizeOfSet(s[i] - 'A') == 1) acorns++;
        }
        int sets =  uf.numDisjointSets() - (26 - n);
        cout << "There are " << sets - acorns << " tree(s) and " << acorns << " acorn(s).\n";
    }
    return 0;
}