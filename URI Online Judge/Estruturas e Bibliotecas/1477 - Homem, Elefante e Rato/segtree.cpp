// URI 1477 - Homem, Elefante e Rato
// Felipe G. Foschiera
#include <stdio.h>
#include <vector>
using namespace std;

struct contagem {
    int cnt[3];
    void shift(int n){
        n %= 3;
        int tmp[3];
        for(int i = 0; i < 3; i++) tmp[i] = cnt[i];
        for(int i = 0; i < 3; i++) 
            cnt[i] = tmp[(i - n + 3) % 3];
    }
 };

 contagem operator + (const contagem a, const contagem b){
    contagem res;
    for(int i = 0; i < 3; i++) res.cnt[i] = a.cnt[i] + b.cnt[i];
    return res;
 }


class SegmentTree {
private:
    vector<contagem> st;
    vector<int> lazy;
    int size;

#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
        if(l == r){
            st[p].cnt[0] = 1;
        }else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    void push(int p, int l, int r){
        st[p].shift(lazy[p]);
        if(l != r){
            lazy[left(p)] += lazy[p];
            lazy[right(p)] += lazy[p];
        }
        lazy[p] = 0;
    }
    contagem query(int p, int l, int r, int a, int b){
        push(p, l, r);
        if(a > r || b < l) return contagem();
        if(l >= a && r <= b) return st[p];
        contagem p1 = query(left(p), l, (l+r)/2, a, b);
        contagem p2 = query(right(p), (l+r)/2+1, r, a, b);
        return p1 + p2;
    }
    void update(int p, int l, int r, int a, int b, int v){
        push(p, l, r);
        if(a > r || b < l) return;
        else if(l >= a && r <= b){
            lazy[p] += v;
            push(p, l, r);
        }else{
            update(left(p), l, (l+r)/2, a, b, v);
            update(right(p), (l+r)/2+1, r, a, b, v);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
public:
    SegmentTree(int N){
        size = N;
        st.assign(4*size, contagem());
        lazy.assign(4*size, 0LL); 
        build(1, 0, size-1);
    }   
    contagem query(int a, int b) { return query(1, 0, size-1, a, b); }
    void update(int a, int b, int v) { update(1, 0, size-1, a, b, v); }
};

int main(){
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF){
        SegmentTree st(N);
        char c;
        int a, b;
        while(M--){
            scanf(" %c %d %d", &c, &a, &b);
            a--, b--;
            if(c == 'M'){
                st.update(a, b, 1);
            }else if(c == 'C'){
                contagem qr = st.query(a, b);
                printf("%d %d %d\n", qr.cnt[0], qr.cnt[1], qr.cnt[2]);
            }
        }
        printf("\n");
    }
    return 0;
}