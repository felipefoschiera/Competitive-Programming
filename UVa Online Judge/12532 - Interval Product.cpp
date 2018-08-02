// UVa 12532 - Interval Product
// Felipe G. Foschiera
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
typedef vector<int> vi;

int comp(int i, int j){
    int a = i < 0 ? -1 : i == 0 ? 0 : 1;
    int b = j < 0 ? -1 : j == 0 ? 0 : 1;
    return a * b;
}


class SegmentTree {
private:
    vi st, A;
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
        if(l == r) st[p] = A[l];
        else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
    int query(int p, int l, int r, int i, int j){
        if(i > r || j < l) return 1;
        if(l >= i && r <= j) return st[p];
        int p1 = query(left(p), l, (l+r)/2, i, j);
        int p2 = query(right(p), (l+r)/2+1, r, i, j);
        return comp(p1, p2);
    }
    void update(int p, int l, int r, int k, int v){
        if(k > r || k < l) return;
        if(l == k && r == k){
            A[k] = v;
            st[p] = A[l];
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
        st.assign(4*size, 0);
        build(1, 0, size-1);
    }
    int query(int a, int b) { return query(1, 0, size-1, a, b); }
    void update(int k, int v){ update(1, 0, size-1, k, v); }
};

int main(){
    int N, K;
    while(scanf("%d %d", &N, &K) != EOF){
        vector<int> A(N);
        for(int i = 0; i < N; i++) scanf("%d", &A[i]);
        SegmentTree st(A);
        string ans = "";
        char op; int a, b;
        while(K--){
            scanf(" %c %d %d", &op, &a, &b);
            if(op == 'C') st.update(a-1, b);
            else if(op == 'P') {
                int query = st.query(a-1, b-1);
                ans += (query == 0 ? '0' : query > 0 ? '+' : '-');
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
} 