#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
const int INF = 1e9;

int comp(int a, int b){
    return max(a, b);
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
        if(a > r || b < l) return 0;
        if(l >= a && r <= b) return st[p];
        int p1 = query(left(p), l, (l+r)/2, a, b);
        int p2 = query(right(p), (l+r)/2+1, r, a, b);
        return comp(p1, p2);
    }
public:
    SegmentTree(vector<int> &_A){
        A = _A;
        size = A.size();
        st.assign(4*size, 0);
        build(1, 0, size-1);
    }
    int query(int a, int b){  return query(1, 0, size-1, a, b); }
};


int main(){
    int n, q;
    while(cin >> n, n){
        cin >> q;
        vector<int> val(n);
        for(int i = 0; i < n; i++) cin >> val[i];
        vector<int> freq(n+1);  
        unordered_map<int,int> cnt;
        for(int i = 0; i < n; i++)
            cnt[val[i]]++;
        for(int i = 0; i < n; i++)
            freq[i] = cnt[val[i]];

        SegmentTree st(freq);
        int l, r;
        while(q--){
            cin >> l >> r;
            l--, r--;
            int res;
            if(val[l] == val[r]){
                res = (r - l + 1);
            }else{
                int left = 0, right = 0;
                while(l < n-1 && l <= r && val[l] == val[l-1]){
                    l++; left++;
                }
                while(r >= 0 && r >= l && val[r] == val[r+1]){
                    r--; right++;
                }
                res = max(left, max(right, st.query(l, r)));
            }
            cout << res << "\n";
        }
    }
    return 0;
}