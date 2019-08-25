#include <bits/stdc++.h>
using namespace std;

struct freq {
    int jogo[3];
    freq() {
        for(int i = 0; i < 3; i++)
            jogo[i] = 0; 
    }
    void shift(int n){
        int temp[3];
        for(int i = 0; i < 3; i++) temp[i] = jogo[i];
        for(int i = 0; i < 3; i++)
            jogo[(i + n) % 3] = temp[i];
    }
    freq operator + (const freq other) const {
        freq nf;
        for(int i = 0; i < 3; i++) nf.jogo[i] = jogo[i] + other.jogo[i];
        return nf;
    }
};


class SegmentTree {
private:
    vector<freq> st;
    vector<int> lazy;
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
        if(l == r){
            st[p] = freq();
            st[p].jogo[0] = 1;
            return;
        }
        int m = (l+r)/2;
        build(left(p), l, m);
        build(right(p), m+1, r);
        st[p] = st[left(p)] + st[right(p)];
    }
    void push(int p, int l, int r){
        st[p].shift(lazy[p]);
        if(l != r){
            lazy[right(p)] += lazy[p];
            lazy[left(p)] += lazy[p];
        }
        lazy[p] = 0;
    }
    void update(int p, int l, int r, int a, int b, int k){
        push(p, l, r);
        if(a > r || b < l) return;
        else if(l >= a && r <= b){
            lazy[p] = k;
            push(p, l, r);
            return;
        }
        update(left(p), l, (l+r)/2, a, b, k);
        update(right(p), (l+r)/2+1, r, a, b, k);
        st[p] = st[left(p)] + st[right(p)];
    }
    freq query(int p, int l, int r, int a, int b){
        push(p, l, r);
        if(a > r || b < l) return freq();
        if(l >= a && r <= b) return st[p];
        int m = (l+r)/2;
        freq p1 = query(left(p), l, m, a, b);
        freq p2 = query(right(p), m+1, r, a, b);
        return p1 + p2;
    }
public:
    SegmentTree(int n){
        size = n;
        st.assign(4*size, freq());
        lazy.assign(4*size, 0);
        build(1, 0, size-1);
    }
    freq query(int a, int b) { return query(1, 0, size-1, a, b); }
    void update(int a, int b) { update(1, 0, size-1, a, b, 1); }
};

int main(){
    int n, m;
    while(cin >> n >> m){
        SegmentTree st(n);
        char op; int a, b;
        for(int i = 0; i < m; i++){
            cin >> op >> a >> b;
            a--, b--;
            if(op == 'M'){
                st.update(a, b);
            }else if(op == 'C'){
                freq q = st.query(a, b);
                cout << q.jogo[0] << " " << q.jogo[1] << " " << q.jogo[2] << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}