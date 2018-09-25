#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 101010
#define MAXLOGN 20

int N, Q, curpos;
vector<int> adj[MAXN];
int chainHead[MAXN], pos[MAXN];
int depth[MAXN], subsize[MAXN], pai[MAXN];

class SegmentTree {
private:
    int st[MAXN*4], lazy[MAXN*4], size;
    #define left(p) (p << 1)
    #define right(p) ((p << 1) + 1)    
    void push(int p, int l, int r){
        if(lazy[p] < 0) return;
        st[p] = (r - l) * lazy[p];
        if(l+1 < r)
            lazy[left(p)] = lazy[right(p)] = lazy[p];
        lazy[p] = -1;
    }
    void update(int p, int l, int r, int a, int b, int v){
        push(p, l, r);
        if(l >= b || r <= a) return;
        if(l >= a && r <= b){
            lazy[p] = v;
            push(p, l, r);
        }else{
            int m = (l+r)/2;
            update(left(p), l, m, a, b, v);
            update(right(p), m, r, a, b, v);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    int query(int p, int l, int r, int a, int b){
        if(l >= b || r <= a) return 0;
        push(p, l, r);
        if(l >= a && r <= b)
            return st[p];
        int m = (l+r)/2;
        return query(left(p), l, m, a, b) + query(right(p), m, r, a, b);
    }
public:
    SegmentTree(int N){
        size = N;
        memset(st, 0, sizeof st);
        memset(lazy, 0, sizeof lazy);
    }
    void update(int a, int b, int v) { update(1, 0, size, a, b, v); }
    int query(int a, int b) { return query(1, 0, size, a, b); }
    
};

void dfs(int u){
    subsize[u] = 1;
    for(auto v : adj[u]){
        if(v != pai[u]){
            pai[v] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
            subsize[u] += subsize[v];
        }
    }
}

void HLD(int u, int par){
    if(par < 0) par = u;
    pos[u] = curpos++;
    chainHead[u] = par;
    int mx = -1;
    for(auto v : adj[u]){
        if(v != pai[u])
            if(mx == -1 || subsize[mx] < subsize[v]) mx = v;
    }
    if(mx != -1) HLD(mx, par);
    for(auto v : adj[u]){
        if(v != pai[u] && v != mx) HLD(v, -1);
    }
}

void update(int x, int y, int k, SegmentTree &st){
    while(chainHead[x] != chainHead[y]){
        if(depth[chainHead[x]] > depth[chainHead[y]]) swap(x, y);
        st.update(pos[chainHead[y]], pos[y]+1, k);
        y = pai[chainHead[y]];
    }
    if(depth[x] > depth[y]) swap(x, y);
    st.update(pos[x], pos[y]+1, k);
}

int query(int x, int y, SegmentTree &st){
    int res = 0;
    while(chainHead[x] != chainHead[y]){
        if(depth[chainHead[x]] > depth[chainHead[y]]) swap(x, y);
        res += st.query(pos[chainHead[y]], pos[y]+1);
        y = pai[chainHead[y]];
    }
    if(depth[x] > depth[y]) swap(x, y);
    res += st.query(pos[x], pos[y]+1);
    return res;
}

void init_hld(){
    pai[0] = -1;
    depth[0] = 0;
    dfs(0);
    curpos = 0;
    HLD(0, -1);
}

int main(){
    scanf("%d %d", &N, &Q);
    int u, v;
    for(int i = 1; i < N; i++){
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init_hld();
    SegmentTree st(N);
    int a, b, c, d;
    while(Q--){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        a--, b--, c--, d--;
        update(a, b, 1, st);
        int res = query(c, d, st);
        update(a, b, 0, st);
        printf("%d\n", res);
    }


    return 0;
}