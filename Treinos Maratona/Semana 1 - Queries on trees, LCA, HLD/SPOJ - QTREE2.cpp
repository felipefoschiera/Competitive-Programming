#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 200010
#define MAXLOGN 20

vector<int> adjList[MAXN], costs[MAXN], ind[MAXN];
int arr[MAXN], depth[MAXN], pa[MAXN][MAXLOGN], otherEnd[MAXN], subsize[MAXN];
int chainNo, chainHead[MAXN], chainInd[MAXN], posInBase[MAXN];
int curpos;

class SegmentTree {
private:
    int st[4*MAXN], size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
        if(l == r){
             st[p] = arr[l];
        }else{
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    int query(int p, int l, int r, int a, int b){
        if(l > r || l > b || r < a) return 0;
        if(l >= a && r <= b) return st[p];
        int q1 = query(left(p), l, (l+r)/2, a, b);
        int q2 = query(right(p), (l+r)/2+1, r, a, b);
        return q1 + q2;
    }
public:
    SegmentTree(int n){
        size = n;
        memset(st, 0, sizeof st);
        build(1, 0, size);
    }
    int query(int a, int b) { return query(1, 0, size, a, b); }

};

void dfs(int node, int prev, int level){
    pa[node][0] = prev;
    depth[node] = level;
    subsize[node] = 1;
    for(int i = 0; i < (int)adjList[node].size(); i++){
        if(adjList[node][i] != prev){
            otherEnd[ind[node][i]] = adjList[node][i];
            dfs(adjList[node][i], node, level+1);
            subsize[node] += subsize[adjList[node][i]];
        }
    }
}

void computeP(int N) {
	for (int j = 1; j < MAXLOGN; j++){
        for (int i = 0; i < N; i++){
            if (pa[i][j-1] != -1)
                pa[i][j] = pa[pa[i][j-1]][j-1];
        }
    }
}

void HLD(int node, int prev, int cost){
    if(chainHead[chainNo] == -1)
        chainHead[chainNo] = node;
    chainInd[node] = chainNo;
    posInBase[node] = curpos;
    arr[curpos++] = cost;
    int sc = -1, ncost;
    for(int i = 0; i < (int)adjList[node].size(); i++){
        if(adjList[node][i] != prev){
            if(sc == -1 || subsize[sc] < subsize[adjList[node][i]]){
                sc = adjList[node][i];
                ncost = costs[node][i];
            }   
        }
    }
    if(sc != -1) HLD(sc, node, ncost);
    for(int i = 0; i < (int)adjList[node].size(); i++){
        if(adjList[node][i] != prev && adjList[node][i] != sc){
            chainNo++;
            HLD(adjList[node][i], node, costs[node][i]);
        }
    }
}


void init_hld(int n){
    chainNo = 0;
    curpos = 0;
    dfs(0, -1 , 0);
    HLD(0, -1, -1);
    computeP(n);
}

int LCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < MAXLOGN; i++){
        if(diff & (1 << i))
            u = pa[u][i];
    }
    if(u == v) return u;
    for(int i = MAXLOGN-1; i >= 0; i--){
        if(pa[u][i] != pa[v][i]){
            u = pa[u][i];
            v = pa[v][i];
        }
    }
    return pa[u][0];
}

int query_up(int u,int v, SegmentTree &st){
	if (u == v)return 0;
	int uchain, vchain = chainInd[v], ans = 0;
	while (1){
		uchain = chainInd[u];
		if (uchain == vchain){
			if (u == v)break;
			ans += st.query(posInBase[v] + 1, posInBase[u]);
		    break;
		}
		ans += st.query(posInBase[chainHead[uchain]], posInBase[u]);
		u = chainHead[uchain];
		u = pa[u][0];
	}
	return ans;
}

int query(int u, int v, SegmentTree &st){
    int lca = LCA(u, v);
    int res = query_up(u, lca, st);
    res += query_up(v, lca, st);
    return res;
}

int getkth(int p, int q, int k){
    int lca = LCA(p, q), d;
    if(lca == p){
        d = depth[q] - depth[p] + 1;
        swap(p, q);
        k = d - k + 1;
    }
    else if(q == lca);
    else {
        d = depth[p] + depth[q] - 2*depth[lca] + 1;
        if(k > depth[p] - depth[lca] + 1){
            k = d - k + 1;
            swap(p, q);
        }
    }
    k--;
    for(int i = MAXLOGN-1; i >= 0; i--){
        if((1 << i) <= k){
            p = pa[p][i];
            k -= (1 << i);
        }
    }
    return p;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            adjList[i].clear();
            ind[i].clear();
            costs[i].clear();
            chainHead[i] = -1;
            for(int j = 0; j < MAXLOGN; j++) pa[i][j] = -1;
        }
        int u, v, w;
        for(int i = 1; i < N; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            costs[u].push_back(w);
            costs[v].push_back(w);
            ind[u].push_back(i-1);
            ind[v].push_back(i-1);
        }
        init_hld(N);
        SegmentTree st(N);
        char s[100];
        while(scanf(" %s", s), s[1] != 'O'){
            scanf("%d %d", &u, &v);
            if(s[0] == 'D'){
                printf("%d\n", query(u-1, v-1, st));
            }else if(s[0] == 'K'){
                int k;
                scanf("%d", &k);
                printf("%d\n", getkth(u-1, v-1, k) + 1);
            }
        }

    }
    return 0;
}