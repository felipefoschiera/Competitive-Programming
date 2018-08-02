/**
 *  Permite consulta em intervalos(neste caso, produto do intervalo, utilizando -1, 0 e 1 para não mexer com os valores grandes)
 *  Permite update em um único valor da sequência. 
 * 
 */

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int comp(int a, int b){
    int i = (a < 0 ? -1 : a == 0 ? 0 : 1);
    int j = (b < 0 ? -1 : b == 0 ? 0 : 1);
    return i*j;
}

class SegmentTree {
private:
    vector<int> st, A;
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
    int query(int p, int l, int r, int a, int b){
        if(a > r || b < l) return 1;
        if(l >= a && r <= b) return st[p];
        int p1 = query(left(p), l, (l+r)/2, a, b);
        int p2 = query(right(p), (l+r)/2+1, r, a, b);
        return comp(p1, p2);
    }
    void update(int p, int l, int r, int ind, int v){
        if(ind > r || ind < l) return;
        else if(l == ind && r == ind){
            A[ind] = v;
            st[p] = A[l];
        }else {
            update(left(p), l, (l+r)/2, ind, v);
            update(right(p), (l+r)/2+1, r, ind, v);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
public:
    SegmentTree(vector<int> &_A){
        A = _A;
        size = A.size();
        st.assign(4*size, 0);
        build(1, 0, size-1);
    }
    int query(int a, int b){  return query(1, 0, size-1, a, b); }
    void update(int ind, int v) { update(1, 0, size-1, ind, v); }
};