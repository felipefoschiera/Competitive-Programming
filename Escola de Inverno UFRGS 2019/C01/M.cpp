#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51010;
const int INF = 1e9;


int n, q;
map<int, set<int>> s;

class SegmentTree { 
private:
    int st[4*MAXN];
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)

int query(int p, int l, int r, int a, int b){
    if(a > r || b < l) return -INF;
    if(l >= a && r <= b) return st[p];
    int p1 = query(left(p), l, (l+r)/2, a, b);
    int p2 = query(right(p), (l+r)/2+1, r, a, b);
    return max(p1, p2);
}

void update(int p, int l, int r, int k, int v){
    if(k > r || k < l) return;
    else if(l == k && r == k){
        st[p] = v;
    }else{
        update(left(p), l, (l+r)/2, k, v);
        update(right(p), (l+r)/2+1, r, k, v);
        st[p] = max(st[left(p)], st[right(p)]);
    }
}
public:
    SegmentTree(int n){
        size = n;
        memset(st, 0, sizeof st);
    }
    int query(int a, int b) { return query(1, 0, size-1, a, b); }
    void update(int k, int v) { update(1, 0, size-1, k, v); }
};

int prox(int x, int i){
    auto it = s[x].upper_bound(i);
    // busca a próxima ocorrencia do tipo de árvore x
    if(it == s[x].end()) return n+1;
    // retorna o índice que encontrou, ou o fim da lista
    return (*it);
}

int anterior(int x, int i){
    auto it = s[x].lower_bound(i);
    // busca a ocorrência anterior do tipo de árvore x, ou retorna 0 se não existe
    if(it == s[x].begin()) return 0;
    it--;
    return (*it);
}

int v[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> q){
        s.clear();
        SegmentTree st(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            s[v[i]].insert(i);
            st.update(i, anterior(v[i], i));
        }
        while(q--){
            char op;
            cin >> op;
            int k, x;
            if(op == 'E'){
                cin >> k;
                int maior = st.query(1, k);
                cout << k - maior << '\n';
            }else if(op == 'C'){
                cin >> k >> x;
                int prx = prox(v[k], k);
                int ant = anterior(v[k], k);
                st.update(prx, ant);
                s[v[k]].erase(k);
                v[k] = x;
                s[v[k]].insert(k);
                prx = prox(v[k], k);
                ant = anterior(v[k], k);
                st.update(k, ant);
                st.update(prx, k);     
            }
        }
    }
    return 0;
}