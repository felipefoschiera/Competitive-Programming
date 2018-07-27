#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> edge;

vector<bool> isPlant;
vector<int> P;

class UnionFind{
private:
    vi p, rank;
    int numSets;
public:
    UnionFind(int N){
        numSets = N;
        p.assign(N, 0);
        rank.assign(N, 0);
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
    bool isPowered(int i){
        int x = findSet(i);
        for(int plant : P)
            if(x == findSet(plant))
                return true;
        return false;
    }
    void unionSet(int i, int j){
        if(isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y]) p[y] = x;
        else{
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};

int kruskal(int N, const vector<edge> &els){
    int mstCost = 0;
    UnionFind UF(N);
    for(int i = 0; i < (int)els.size(); i++){
        edge e = els[i];
        if(!UF.isSameSet(e.second.first, e.second.second)
        && !(UF.isPowered(e.second.first) && UF.isPowered(e.second.second))){
            UF.unionSet(e.second.first, e.second.second);
            mstCost += e.first;
        }
    }
    return mstCost;
}

int main(){
    int T, tc;
    int N, M, K, i, a, b, c;
    scanf("%d", &T);
    for(tc = 1; tc <= T; tc++){
        scanf("%d %d %d", &N, &M, &K);
        vector<edge> els;
        isPlant.assign(N, false);
        P.clear();
        for(i = 0; i < K; i++){
            scanf("%d", &a);
            P.push_back(--a);
            isPlant[a] = true;
        }
        for(i = 0; i < M; i++){
            scanf("%d %d %d", &a, &b, &c);
            a--; b--;
            els.push_back({c, {a, b}});
        }
        sort(els.begin(), els.end());
        printf("Case #%d: %d\n", tc, kruskal(N, els));
    }
    return 0;
}
