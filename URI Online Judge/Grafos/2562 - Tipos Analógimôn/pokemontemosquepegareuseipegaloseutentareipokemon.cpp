#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

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

int main(){
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF){
        UnionFind uf(N);
        int a, b;        
        for(int i = 0; i < M; i++){
            scanf("%d %d", &a, &b);
            uf.unionSet(a, b);
        }
        int e;
        scanf("%d", &e);
        printf("%d\n", uf.sizeOfSet(e));
    }

    return 0; 
}