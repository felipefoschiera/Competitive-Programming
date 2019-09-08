#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef pair<int, int> ii;

ii comp(ii a, ii b){
	if(a.first != b.first){
		return a.first > b.first ? a : b;
	}
	return a.second < b.second ? a : b;

}

class SegmentTree {
private:
	vector<ii> st;
	vector<int> lazy;
	int size;
#define left(p) (p << 1)
#define right(p) (1 + (p << 1))
	void build(int p, int l, int r, int* A){
		if(l == r) {
			st[p] = {A[l], l};
			return;
		}
		int m = (l+r)/2;
		build(left(p), l, m, A);
		build(right(p), m+1, r, A);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	void push(int p, int l, int r){
		st[p].first += lazy[p];
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
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	ii query(int p, int l, int r, int a, int b){
		push(p, l, r);
		if(a > r || b < l) return {-INF, -1};
		if(l >= a && r <= b) return st[p];
		int m = (l+r)/2;
		ii p1 = query(left(p), l, m, a, b);
		ii p2 = query(right(p), m+1, r, a, b);
		return comp(p1, p2);
	}
public:
	SegmentTree(int *bg, int *en){
		size = (int)(en - bg);
		st.assign(4*size, ii());
		lazy.assign(4*size, 0);
		build(1, 0, size-1, bg);
	}
	int query(int a, int b) { return query(1, 0, size-1, a, b).second; }
	void update(int a, int b, int k) { update(1, 0, size-1, a, b, k); }
};

int A[100100];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	while(cin >> n >> q){
		for(int i = 0; i < n; i++) cin >> A[i];
		SegmentTree st(A, A+n);
		char tipo;
		int i, j, v;
		while(q--){
			cin >> tipo >> i >> j;
			if(tipo == 'A'){
				cin >> v;
				st.update(i-1, j-1, v);
			}else if(tipo == 'C'){
				cout << st.query(i-1, j-1) + 1 << '\n';
			}
		}

	}
	return 0;
}