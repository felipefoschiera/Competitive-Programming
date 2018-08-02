// URI 2531 - Compras em FdI
// Felipe G. Foschiera

#include <stdio.h>
#include <vector>
#define INF ((int)1e9)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

ii comp(ii i, ii j){
    return ii(max(i.first, j.first), min(i.second, j.second));
}


class SegmentTree {
private:
    vi A;
    vector<ii> st;
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
        if(l == r) st[p] = ii(A[l], A[l]);
        else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
    ii query(int p, int l, int r, int i, int j){
        if(i > r || j < l) return ii(-INF, INF);
        if(l >= i && r <= j) return st[p];
        ii p1 = query(left(p), l, (l+r)/2, i, j);
        ii p2 = query(right(p), (l+r)/2+1, r, i, j);
        return comp(p1, p2);
    }
    void update(int p, int l, int r, int k, int v){
        if(k > r || k < l) return;
        if(l == k && r == k){
            A[k] = v;
            st[p] = ii(A[l], A[l]);
        }else {
            update(left(p), l, (l+r)/2, k, v);
            update(right(p), (l+r)/2+1, r, k, v);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }

public:
    SegmentTree(vector<int> &_A){
        A = _A;
        size = (int)A.size();
        st.assign(4*size, ii());
        build(1, 0, size-1);
    }
    ii query(int a, int b) { return query(1, 0, size-1, a, b); }
    void update(int k, int v){ update(1, 0, size-1, k, v); }
};

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        vector<int> A(N);
        for(int i = 0; i < N; i++) scanf("%d", &A[i]);
        SegmentTree st(A);
        int Q;
        scanf("%d", &Q);
        while(Q--){
            int op, a, b;
            scanf("%d %d %d", &op, &a, &b);
            if(op == 1) st.update(a-1, b);
            else if(op == 2) {
                ii query = st.query(a-1, b-1);
                printf("%d\n", query.first - query.second);
            }
        }
    }
    return 0;
} 