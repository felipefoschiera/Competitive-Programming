#include <bits/stdc++.h>
using namespace std;
 
int comp(int a, int b){
    return a ^ b;
}
 
class SegmentTree {
private:
    vector<int> st, lazy, A;
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
     lazy[p] = 0;
        if(l == r){
            st[p] = A[l];
        }
        else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
 
    void push(int p, int l, int r){
        if(l != r && lazy[p] != 0){
            int mid = (l+r)/2;
            lazy[left(p)] = lazy[p];
            lazy[right(p)] = lazy[p];
            st[left(p)] = ((mid - l + 1) % 2 == 0) ? 0 : lazy[p];
            st[right(p)] = ((r - mid) % 2 == 0) ? 0 : lazy[p];
        }
        lazy[p] = 0;
    }

    int query(int p, int l, int r, int a, int b){
        push(p, l, r);       
        if(a > r || b < l) return 0;
        if(l >= a && r <= b) {
            return st[p];
        }
        int p1 = query(left(p), l, (l+r)/2, a, b);
        int p2 = query(right(p), (l+r)/2+1, r, a, b);
        return comp(p1, p2);
}
    void update(int p, int l, int r, int a, int b, int k){
        push(p, l, r);
        if(a > r || b < l) return;
        else if(l >= a && r <= b){
            int interv = (r - l + 1);
            st[p] = (interv % 2 == 0) ? 0 : k;
            lazy[p] = k;
            push(p, l, r);
            return;
        }
        update(left(p), l, (l+r)/2, a, b, k);
        update(right(p), (l+r)/2+1, r, a, b, k);
        st[p] = comp(st[left(p)], st[right(p)]);
    }
public:
    SegmentTree(vector<int> &_A){
        size = _A.size();
        A = _A;
        st.assign(4*size, 0);
        lazy.assign(4*size, 0);
        build(1, 0, size-1);
    }
    int query(int a, int b) { return query(1, 0, size-1, a, b); }
    void update(int a, int b, int k) { update(1, 0, size-1, a, b, k); }
 
};
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int n, m;
    int x, y, v;
    cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    SegmentTree st(A);
   
    while(m--){
        cin >> x >> y >> v;
        st.update(x-1, y-1, v);
 
        int query = st.query(0, n-1);
        //cout << "q = " << query << '\n';
        cout << ((query) ? "Possivel" : "Impossivel") << '\n';
    }
 
        return 0;
}