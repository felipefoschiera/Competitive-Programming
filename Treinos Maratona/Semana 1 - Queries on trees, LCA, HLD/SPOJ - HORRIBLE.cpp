#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 101010
typedef long long ll;


class SegmentTree {
private:
    ll st[4*MAXN], lazy[4*MAXN];
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void push(int p, int l, int r){
        if(l != r){
            lazy[left(p)] += lazy[p];
            lazy[right(p)] += lazy[p];
        }
        st[p] += (r - l + 1) * lazy[p];
        lazy[p] = 0;
    }
    void update(int p, int l, int r, int a, int b, int v){
        push(p, l, r);
        if(a > r || b < l) return;
        if(l >= a && r <= b){
            lazy[p] += v;
            push(p, l, r);
        }else{
            update(left(p), l, (l+r)/2, a, b, v);
            update(right(p), (l+r)/2+1, r, a, b, v);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    ll query(int p, int l, int r, int a, int b){
        push(p, l, r);
        if(a > r || b < l) return 0;
        if(l >= a && r <= b) return st[p];
        ll q1 = query(left(p), l, (l+r)/2, a, b);
        ll q2 = query(right(p), (l+r)/2+1, r, a, b);
        return q1 + q2;
    }
public:
    SegmentTree(int N){
        size = N;
        memset(st, 0, sizeof st);
        memset(lazy, 0, sizeof lazy);
    }
    void update(int a, int b, int v) { update(1, 0, size-1, a, b, v); }
    ll query(int a, int b) { return query(1, 0, size-1, a, b); }
};

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, C;
        scanf("%d %d", &N, &C);
        int op, p, q, v;
        SegmentTree st(N);
        while(C--){
            scanf("%d %d %d", &op, &p, &q);
            if(op == 0){
                scanf("%d", &v);
                st.update(p-1, q-1, v);
            }else{
                printf("%lld\n", st.query(p-1, q-1));
            }
        }
    }
    return 0;
}