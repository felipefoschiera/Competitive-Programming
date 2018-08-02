#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int comp(int a, int b){
     return a + b;
}

class SegmentTree {
private:
    vector<int> st, lazy;
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
    int query(int p, int l, int r, int a, int b){
        push(p, l, r);
        if(a > r || b < l) return 0;
        if(l >= a && r <= b) return st[p];
        int p1 = query(left(p), l, (l+r)/2, a, b);
        int p2 = query(right(p), (l+r)/2+1, r, a, b);
        return comp(p1, p2);
    }
    void update(int p, int l, int r, int a, int b, int k){
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
    int query(int a, int b){  return query(1, 0, size-1, a, b); }
    void update(int a, int b, int k) { update(1, 0, size-1, a, b, k); }
};