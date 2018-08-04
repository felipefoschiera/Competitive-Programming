#include <stdio.h>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

ii comp(ii a, ii b){
    if(a.first != b.first) return a.first > b.first ? a : b;
    return a.second < b.second ? a : b;
}

class SegmentTree {
private:
    vector<int> lazy, A;
    vector<ii> st;
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
        if(l == r) st[p] = ii(A[l], l+1);
        else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            ii p1 = st[left(p)], p2 = st[right(p)];
            st[p] = comp(p1, p2);
        }
    }
    void push(int p, int l, int r){
        st[p].first += lazy[p];
        if(l != r){
            lazy[left(p)] += lazy[p];
            lazy[right(p)] += lazy[p];
        }
        lazy[p] = 0;
    }
    ii query(int p, int l, int r, int a, int b){
        push(p, l, r);
        if(a > r || b < l) return ii();
        if(l >= a && r <= b) return st[p];
        ii p1 = query(left(p), l, (l+r)/2, a, b);
        ii p2 = query(right(p), (l+r)/2+1, r, a, b);
        return comp(p1, p2);
    }
    void update(int p, int l, int r, int a, int b, int v){
        push(p, l, r);
        if(a > r || b < l) return;
        else if(l >= a && r <= b){
            lazy[p] = v;
            push(p, l, r);
        }else{
            update(left(p), l, (l+r)/2, a, b, v);
            update(right(p), (l+r)/2+1, r, a, b, v);
            ii p1 = st[left(p)], p2 = st[right(p)];
            st[p] = comp(p1, p2);           

        }
    }

public:
    SegmentTree(vector<int> &_A){
        A = _A;
        size = A.size();
        st.assign(4*size, ii());
        lazy.assign(4*size, 0);
        build(1, 0, size-1);
    }
    int query(int a, int b) { return query(1, 0, size-1, a, b).second; }
    void update(int a, int b, int v) { update(1, 0, size-1, a, b, v); }

};

int main(){
    int N, Q;
    while(scanf("%d %d", &N, &Q) != EOF){
        vector<int> A(N);
        for(int i = 0; i < N; i++) scanf("%d", &A[i]);
        SegmentTree st(A);
        char op;
        int a, b, v;
        while(Q--){
            scanf(" %c %d %d", &op, &a, &b);
            a--, b--;
            if(op == 'C'){
                printf("%d\n", st.query(a, b));
            }else if(op == 'A'){
                scanf("%d", &v);
                st.update(a, b, v);
            }
        }
    }
    return 0;
}