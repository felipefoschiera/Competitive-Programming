#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;



class SegmentTree {
private:
	vector<ll> st;
	vector<ll> A;
	int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
	void build(int p, int l, int r){
		if(l == r){
			st[p] |= 1LL << (A[l]-1);
		}else{
			build(left(p), l, (l+r)/2);
			build(right(p), (l+r)/2+1, r);
            st[p] = st[left(p)] | st[right(p)];
		}
	}
	void update(int p, int l, int r, int ind, int v){
		if(ind > r || ind < l) return;
		if(l == ind && r == ind){
			ll old = A[l];
            st[p] = (st[p] & ~(1LL << (old-1)));
			A[l] = v;
            st[p] |= (1LL << (v-1));
		}else{
			update(left(p), l, (l+r)/2, ind, v);
			update(right(p), (l+r)/2+1, r, ind, v);
			st[p] = st[left(p)] | st[right(p)];
		}
	}
	ll query(int p, int l, int r, int a, int b){
		if(a > r || b < l) return 0LL;
		if(l >= a && r <= b) return st[p];
		ll p1 = query(left(p), l, (l+r)/2, a, b);
		ll p2 = query(right(p), (l+r)/2+1, r, a, b);
		return p1 | p2;
	}
public:
	SegmentTree(vector<ll> &_A){
		A = _A;
		size = A.size();
		st.assign(4*size, 0LL);
		build(1, 0, size-1);
	}
	void update(int ind, ll v) { update(1, 0, size-1, ind, v); }
	ll query(int a, int b) { return __builtin_popcountll(query(1, 0, size-1, a, b))  ; }
};

int main(){
	int N, Q, M;
	while(scanf("%d %d %d", &N, &Q, &M) != EOF){
		vector<ll> A(N);
		for(int i = 0; i < N; i++) scanf("%lld", &A[i]);
		SegmentTree st(A);
		while(Q--){
			int op, l;
            ll r;
			scanf("%d %d %lld", &op, &l, &r);
			if(op == 2){
				st.update(l-1, r);
			}else if(op == 1){
				printf("%lld\n", st.query(l-1, r-1));
			}
		}
	}
	return 0;
}