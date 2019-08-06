#include <cstdio>
#include <vector>
using namespace std;
#define INF ((int)1e9)
#define MAXN 101010
#define MAXLOGN 20

typedef pair<int, int> ii;

vector <int> adj[MAXN], costs[MAXN];
int baseArray[MAXN], ptr;
int chainNo, chainInd[MAXN], chainHead[MAXN], posInBase[MAXN];
int depth[MAXN], pa[MAXLOGN][MAXN], subsize[MAXN];
    
ii comp(const ii a, const ii b){
    return ii(min(a.first, b.first), max(a.second, b.second));

}

class SegmentTree {
    
private:
    ii st[MAXN*4];
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
        if(l == r-1){ 
            if(baseArray[l] == -1) st[p] = ii(INF, -INF);
            else st[p] = ii(baseArray[l], baseArray[l]);
        }
        else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2, r);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
    ii query(int p, int l, int r, int a, int b) {
        if(l >= b || r <= a) return ii(INF, -INF);
        if(l >= a && r <= b) return st[p];
        int m = (l+r)/2;
        ii q1 = query(left(p), l , m, a, b);
        ii q2 = query(right(p), m, r, a, b);
        return comp(q1, q2);
    }
public:
    SegmentTree(int n){
        size = n;
        build(1, 0, size);
    }
    ii query(int a, int b) { return query(1, 0, size, a, b); }
    
};

    
ii query_up(int u, int v, SegmentTree &st) {
    if(u == v) return ii(INF, -INF); 
    int uchain, vchain = chainInd[v];
    ii ans = ii(INF, -INF);
    while(1) {
        uchain = chainInd[u];
        if(uchain == vchain) {
            if(u == v) break;
            ii x = st.query(posInBase[v]+1, posInBase[u]+1);
            ans = comp(ans, x);
            break;
        }
        ii x = st.query(posInBase[chainHead[uchain]], posInBase[u]+1);
        ans = comp(ans, x);
        u = chainHead[uchain]; 
        u = pa[0][u];
    }
    return ans;
}


int LCA(int u, int v) {
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v];
    for(int i=0; i<MAXLOGN; i++) if( (diff>>i)&1 ) u = pa[i][u];
    if(u == v) return u;
    for(int i=MAXLOGN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
        u = pa[i][u];
        v = pa[i][v];
    }
    return pa[0][u];
}
    
ii query(int u, int v, SegmentTree &st) {
    int lca = LCA(u, v);
    ii res = query_up(u, lca, st); 
    ii b = query_up(v, lca, st);
    res = comp(res, b);
    return res;
}

void HLD(int u, int par, int cost){
    if(chainHead[chainNo] == -1)
        chainHead[chainNo] = u;
    chainInd[u] = chainNo;
    posInBase[u] = ptr;
    baseArray[ptr++] = cost;
    int sc = -1, ncost;
    for(int i = 0; i < (int)adj[u].size(); i++)
        if(adj[u][i] != pa[0][u]) {
            if(sc == -1 || subsize[sc] < subsize[adj[u][i]]) {
                sc = adj[u][i];
                ncost = costs[u][i];
            }
        }
    if(sc != -1) HLD(sc, u, ncost);
    for(int i = 0; i < (int)adj[u].size(); i++)
        if(adj[u][i] != pa[0][u]) {
            if(sc != adj[u][i]) {
                chainNo++;
                HLD(adj[u][i], u, costs[u][i]);
            }
        }
}

void dfs(int cur, int prev) {
    pa[0][cur] = prev;
    subsize[cur] = 1;
    for(int i = 0; i < (int)adj[cur].size(); i++)
        if(adj[cur][i] != prev) {
            depth[adj[cur][i]] = depth[cur] + 1;
            dfs(adj[cur][i], cur);
            subsize[cur] += subsize[adj[cur][i]];
        }
}
    
void computeParentLCA(int n){   
    for(int i = 1; i < MAXLOGN; i++)
        for(int j = 0; j < n; j++)
            if(pa[i-1][j] != -1)
                pa[i][j] = pa[i-1][pa[i-1][j]];
    
}

void init_hld(int n){
    chainNo = 0;
    ptr = 0;
    depth[0] = 0;
    dfs(0, -1);
    HLD(0, -1, -1);
    computeParentLCA(n);
}

int main(){
    int N;
    scanf("%d", &N);
    int u, v, w;
    for(int i = 0; i < N; i++){
        chainHead[i] = -1;
        for(int j = 0; j < MAXLOGN; j++) pa[j][i] = -1;
    }
    for(int i = 1; i < N; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        costs[u].push_back(w);
        costs[v].push_back(w);
    }
    init_hld(N);
    SegmentTree st(N);
    int Q;
    scanf("%d", &Q);
    while(Q--){
        scanf("%d %d", &u, &v);
        u--, v--;
        ii res = query(u, v, st);
        printf("%d %d\n", res.first, res.second);
    }
    return 0;
}