#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#define MAX 102345
using namespace std;

struct frequencia {
    int freq[9];
    
    void shift(int n){
        int temp[9];
        for(int i = 0; i < 9; i++) temp[i] = freq[i];
        for(int i = 0; i < 9; i++) {
            freq[i] = temp[(i-n+9)%9];
        }
    }

    int maximo() {
        int res = 0;
        for(int i = 0; i < 9; i++) if(freq[i] >= freq[res]) res = i;
        return res;
    }
};

frequencia operator + (const frequencia a, const frequencia b){
    frequencia nova;
    for(int i = 0; i < 9; i++) nova.freq[i] = a.freq[i] + b.freq[i];
    return nova;
}


class SegmentTree {
private:
    vector<int> lazy;
    frequencia st[4*MAX];
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r, int *A){
        if(l == r){
            st[p].freq[A[l]] = 1;
        }else {
            build(left(p), l, (l+r)/2, A);
            build(right(p), (l+r)/2+1, r, A);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    void push(int p, int l, int r){
        st[p].shift(lazy[p]);
        if(l != r){
            lazy[right(p)] = (lazy[right(p)] + lazy[p]) % 9;
            lazy[left(p)] = (lazy[left(p)] + lazy[p]) % 9;
        }
        lazy[p] = 0;
    }
    frequencia query(int p, int l, int r, int a, int b){
        push(p, l, r);
        if(a > r || b < l) return frequencia();
        if(l >= a && r <= b) return st[p];
        frequencia p1 = query(left(p), l, (l+r)/2, a, b);
        frequencia p2 = query(right(p), (l+r)/2+1, r, a, b);
        return p1 + p2;
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
            st[p] = st[left(p)] + st[right(p)];
        }
    }
public:
    SegmentTree(int *arr, int *end){
        size = (int)(end-arr);
        memset(st, 0, sizeof st);
        lazy.assign(4*size, 0);
        build(1, 0, size-1, arr);
    }
    frequencia query(int a, int b){  return query(1, 0, size-1, a, b); }
    void update(int a, int b, int k) { update(1, 0, size-1, a, b, k); }
};

int orig[MAX];

int main(){
    int N, Q;
    while(scanf("%d %d", &N, &Q) != EOF){
        for(int i = 0; i < N; i++) orig[i] = 1;
        SegmentTree st(orig, orig+N);
        int a, b;
        while(Q--){
            scanf("%d %d", &a, &b);
            int mostfreq = st.query(a, b).maximo();
            st.update(a, b, mostfreq);
        }
        for(int i = 0; i < N; i++) printf("%d\n", st.query(i, i).maximo());
    }
    return 0;
}