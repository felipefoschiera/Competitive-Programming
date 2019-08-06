#include <stdio.h>
#include <cstring>
#define MAX 100005
using namespace std;


int queryInterval[9];

class SegmentTree {
private:
    int st[4*MAX][9];
    int lazy[4*MAX];
    int temp[9];
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r){
        if(l == r){
            st[p][1] = 1;
        }else{
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p][1] = st[left(p)][1] + st[right(p)][1];
        }
    }
    void push(int p, int l, int r){
        for(int i = 0; i < 9; i++) temp[i] = st[p][i];
        for(int i = 0; i < 9; i++) st[p][i] = temp[(i-lazy[p]+9)%9];
        if(l != r){
            lazy[right(p)] = (lazy[right(p)] + lazy[p]) % 9;
            lazy[left(p)] = (lazy[left(p)] + lazy[p]) % 9;
        }
        lazy[p] = 0;
    }
    void query(int p, int l, int r, int a, int b){
        push(p, l, r);
        if(a > r || b < l) return;
        if(l >= a && r <= b){
            for(int i = 0; i < 9; i++) queryInterval[i] += st[p][i];
        }else{
            query(left(p), l, (l+r)/2, a, b);
            query(right(p), (l+r)/2+1, r, a, b);
        }
    }

    void update(int p, int l, int r, int a, int b, int k){
        push(p, l, r);
        if(a > r || b < l) return;
        if(l >= a && r <= b) {
            lazy[p] += k;
            push(p, l, r);
        }else {
            update(left(p), l, (l+r)/2, a, b, k);
            update(right(p), (l+r)/2+1, r, a, b, k);
            for(int i = 0; i < 9; i++)
                st[p][i] = st[left(p)][i] + st[right(p)][i];
            
        }
    }
public:
    void init(int N){
        size = N;
        memset(st, 0, sizeof st);
        memset(lazy, 0, sizeof lazy);
        build(1, 0, size-1);
    }
    void query(int a, int b){
        memset(queryInterval, 0, sizeof queryInterval);
        query(1, 0, size-1, a, b);
    }
    void update(int a, int b, int k) { update(1, 0, size-1, a, b, k); }
};


SegmentTree st;

int main(){
    int N, Q;
    while(scanf("%d %d", &N, &Q) != EOF){
        st.init(N);
        int a, b;
        while(Q--){
            scanf("%d %d", &a, &b);
            st.query(a, b);
            int mostfreq = 0;
            for(int k = 0; k < 9; k++)
                if(queryInterval[k] >= queryInterval[mostfreq])
                   mostfreq = k;

            st.update(a, b, mostfreq);
        }
        for(int i = 0; i < N; i++){
            st.query(i, i);
            int max = 0;
            for(int j = 0; j < 9; j++){
                if(queryInterval[j] > queryInterval[max])
                    max = j;
            }
            printf("%d\n", max);
        }
    }
    return 0;
}