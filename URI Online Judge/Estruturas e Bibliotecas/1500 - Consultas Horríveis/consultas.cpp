#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

ll comp(ll a, ll b){
     return a + b;
}

class SegmentTree {
private:
    vector<ll> st, lazy;
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void push(int p, int l, int r){
        if(l != r){
            lazy[right(p)] += lazy[p];
            lazy[left(p)] += lazy[p];
        }
        st[p] += (r - l + 1) * lazy[p];
        lazy[p] = 0;
    }
    ll query(int p, int l, int r, int a, int b){
        push(p, l, r);
        if(a > r || b < l) return 0;
        if(l >= a && r <= b) return st[p];
        ll p1 = query(left(p), l, (l+r)/2, a, b);
        ll p2 = query(right(p), (l+r)/2+1, r, a, b);
        return comp(p1, p2);
    }
    void update(int p, int l, int r, int a, int b, ll k){
        push(p, l, r);
        if(a > r || b < l) return;
        else if(l >= a && r <= b) {
            lazy[p] = k;
            push(p, l, r);
        }else {
            update(left(p), l, (l+r)/2, a, b, k);
            update(right(p), (l+r)/2+1, r, a, b, k);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
public:
    SegmentTree(int sz){
        size = sz;
        st.assign(4*size, 0);
        lazy.assign(4*size, 0);
    }
    ll query(int a, int b){  return query(1, 0, size-1, a, b); }
    void update(int a, int b, ll k) { update(1, 0, size-1, a, b, k); }
};

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, C;
        scanf("%d %d", &N, &C);
        SegmentTree st(N);
        while(C--){
            int op, p, q;
            ll v;
            scanf("%d", &op);
            if(op == 0){
                scanf("%d %d %lld", &p, &q, &v);
                st.update(p-1, q-1, v);
            }else if(op == 1){
                scanf("%d %d", &p, &q);
                printf("%lld\n", st.query(p-1, q-1));
            }
        }
    }
    return 0;
}