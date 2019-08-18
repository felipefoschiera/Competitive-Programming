#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> p, rnk, setSize;
    int numSets;
public:
    UnionFind(int N){
        setSize.assign(N, 1);
        numSets = N;
        rnk.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int x){
        return (p[x] == x ? x : p[x] = findSet(p[x]));
    }
    bool isSameSet(int x, int y){
        return findSet(x) == findSet(y);
    }
    void unionSet(int x, int y){
        if(!isSameSet(x, y))
        {
            int i = findSet(x), j = findSet(y);
            numSets--;

            if(rnk[i] > rnk[j]){
                p[j] = i;
                setSize[i] += setSize[j];
            }else{
                p[i] = j;
                setSize[j] += setSize[i];
                if(rnk[i] == rnk[j]) rnk[j]++;
            }
        }
    }
    int sizeOfSet(int i) { return setSize[findSet(i)];}
};

const int MAX = 1010;

vector<int> adj[MAX];
bool visited[MAX];

void dfs(int u){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v]) dfs(v);
    }
}

int main(){
    int n, m, r, e;
    while(cin >> n >> m >> r >> e){
        UnionFind uf(n);
        int u, v;
        for(int i = 0; i < n; i++){
            visited[i] = 0;
            adj[i].clear();
        }
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(!uf.isSameSet(u, v))
            {
                uf.unionSet(u, v);
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i);
                int tem = adj[i].size();
                for(int j = 0; j < n; j++){
                    if(i != j && uf.isSameSet(i, j)){
                        tem += adj[j].size();
                    }
                }
                int tamSet = uf.sizeOfSet(i);
                int arestas = ((tamSet*(tamSet-1))/2);
                int precisa = arestas - (tem/2);

                int custoA = tamSet * e;
                int custoB = precisa * r;

                res += min(custoA, custoB);

            }
        }
        cout << res << '\n';
    }
    return 0;
}
