#include <cstdio>
#include <vector>
using namespace std;
    
#define MAXN 10100
#define MAXLOGN 14
    
vector <int> adj[MAXN], costs[MAXN], indexx[MAXN];
int baseArray[MAXN], ptr;
int chainNo, chainInd[MAXN], chainHead[MAXN], posInBase[MAXN];
int depth[MAXN], pa[MAXLOGN][MAXN], otherEnd[MAXN], subsize[MAXN];
    
class SegmentTree {
private:
    int st[MAXN*4], size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
        if(l == r-1) st[p] = baseArray[l];
        else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2, r);
            st[p] = max(st[left(p)], st[right(p)]);
        }
    }
    void update(int p, int l, int r, int k, int val) {
        if(l > k || r <= k) return;
        if(l == k && l == r-1) {
            st[p] = val;
            return;
        }
        int m = (l+r)/2;
        update(left(p), l, m, k, val);
        update(right(p), m, r, k, val);
        st[p] = max(st[left(p)], st[right(p)]); 
    }
    
    int query(int p, int l, int r, int a, int b) {
        if(l >= b || r <= a) return -1;
        if(l >= a && r <= b) return st[p];
        int m = (l+r)/2;
        int q1 = query(left(p), l , m, a, b);
        int q2 = query(right(p), m, r, a, b);
        return max(q1, q2);
    }
public:
    SegmentTree(int n){
        size = n;
        build(1, 0, size);
    }
    void update(int k, int v) { update(1, 0, size, k, v); }
    int query(int a, int b) { return query(1, 0, size, a, b); }
    
};

    
int query_up(int u, int v, SegmentTree &st) {
    if(u == v) return 0; 
    int uchain, vchain = chainInd[v], ans = -1;
    while(1) {
        uchain = chainInd[u];
        if(uchain == vchain) {
            if(u == v) break;
            int x = st.query(posInBase[v]+1, posInBase[u]+1);
            if(x > ans) ans = x;
            break;
        }
        int x = st.query(posInBase[chainHead[uchain]], posInBase[u]+1);
        if(x > ans) ans = x;
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
    
int query(int u, int v, SegmentTree &st) {
    int lca = LCA(u, v);
    int res = query_up(u, lca, st); 
    int b = query_up(v, lca, st);
    if(b > res) res = b; 
    return res;
}
    
void change(int i, int val, SegmentTree &st) {
    int u = otherEnd[i];
    st.update(posInBase[u], val);
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
            otherEnd[indexx[cur][i]] = adj[cur][i];
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
    depth[0] = 0;
    dfs(0, -1);
    HLD(0, -1, -1);
    computeParentLCA(n);
}