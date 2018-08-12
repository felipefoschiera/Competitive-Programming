// URI 1862 - Casas de Westeros
// Felipe G. Foschiera
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1123
using namespace std;
typedef vector<int> vi;

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N){
        setSize.assign(N, 1);
        numSets = N;
        p.assign(N, 0);
        rank.assign(N, 0);
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i ? i : p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            numSets--;
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
                setSize[x] += setSize[y];
            }else{
                p[x] = y; setSize[y] += setSize[x];
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets(){ return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
    int N;
    char mat[MAX][MAX];
    while(cin >> N){
        UnionFind uf(N);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'S')
                    uf.unionSet(i, j); }
        bool ok = true;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                bool isSame = uf.isSameSet(i, j);
                if((isSame && mat[i][j] == 'D') || ((!isSame) && mat[i][j] == 'S'))
                    ok = false; }
        if(!ok) cout << -1 << '\n';
        else {
            vector<int> sizes;
            int num = uf.numDisjointSets();
            cout << num << '\n';
            vector<bool> computed(MAX, false);
            for(int i = 0; i < N; i++){
                int st = uf.findSet(i);
                if(!computed[st]){
                    sizes.push_back(uf.sizeOfSet(i));
                    computed[st] = true;
                }
            }
            sort(sizes.rbegin(), sizes.rend());
            for(int i = 0; i < num; i++) cout << sizes[i] << (i == num -1 ? '\n' : ' ');
        }
    }
    return 0;
}