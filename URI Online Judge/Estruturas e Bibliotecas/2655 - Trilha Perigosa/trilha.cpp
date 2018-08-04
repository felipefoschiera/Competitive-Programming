#include <stdio.h>
#include <vector>
#define MAX 55
using namespace std;


int M;

struct monstros {
    int tps[MAX] = {0};

    int count(){
        int res = 0;
        for(int i = 1; i <= M; i++) if(tps[i] > 0) res++;
        return res;
    }    

};

monstros operator + (const monstros a, const monstros b){
    monstros novo;
    for(int i = 1; i <= M; i++) novo.tps[i] = a.tps[i] + b.tps[i];
    return novo;
}

class SegmentTree {
private:
    vector<int> A;
    vector<monstros> st;
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
        if(l == r) st[p].tps[A[l]]++;
        else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    monstros query(int p, int l, int r, int a, int b){
        if(a > r || b < l) return monstros();
        if(l >= a && r <= b) return st[p];
        monstros p1 = query(left(p), l, (l+r)/2, a, b);
        monstros p2 = query(right(p), (l+r)/2+1, r, a, b);
        return p1 + p2;
    }
    void update(int p, int l, int r, int k, int v){
        if(k > r || k < l) return;
        if(l == k && r == k){
            int ant = A[k];
            A[k] = v;
            st[p].tps[ant]--;
            st[p].tps[v]++;
        }else{
            update(left(p), l, (l+r)/2, k, v);
            update(right(p), (l+r)/2+1, r, k, v);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
public:
    SegmentTree(vector<int> &_A){
        A = _A;
        size = A.size();
        st.assign(4*size, monstros());
        build(1, 0, size-1);
    }
    monstros query(int a, int b) { return query(1, 0, size-1, a, b); }
    void update(int k, int v) { update(1, 0, size-1, k, v); }
};

int main(){
    int N, Q;
    while(scanf("%d %d %d", &N, &Q, &M) != EOF){
        vector<int>A(N);
        for(int i = 0; i < N; i++) scanf("%d", &A[i]);
        SegmentTree st(A);
        int op, a, b;
        while(Q--){
            scanf("%d %d %d", &op, &a, &b);
            if(op == 1){
                printf("%d\n", st.query(a-1, b-1).count());
            }else if(op == 2){
                st.update(a-1, b);
            }
        }
    }
    return 0;
}