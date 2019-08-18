#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

/**
 * 	A Árvore de Segmentos é uma estrutura ótima para resolver esse problema, visto que
 * 	permite a atualização em um ponto e requer consultas em interval.
 * 	A árvore de segmentos mantem, em cada ponto, uma bitmask, com estados 1 e 0, já que
 * 	apenas nos interessa se um determinado tipo de monstro existe ou não, e não sua quantidade.
 * 	Como a quantidade de tipos de monstros máxima é 50, podemos utilizar o long long, que tem 64 bits.
 * 	
 * 
 */

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
			// A operação OR com st[p] ativa o bit do tipo de monstro A[l] na bitmask st[p]
			// (-1 pois é indexado a partir de 0).
		}else{
			build(left(p), l, (l+r)/2);
			build(right(p), (l+r)/2+1, r);
            st[p] = st[left(p)] | st[right(p)]; // Na hora de unir segmentos, tanto na build quanto
			// no update e na resposta da query, utilizamos o OR, combinando as espécies existentes em outra bitmask.
		}
	}
	void update(int p, int l, int r, int ind, int v){
		if(ind > r || ind < l) return;
		if(l == ind && r == ind){
			// Para trocar uma espécie de monstro, desativamos o bit antigo e ativamos o bit novo.
			// Para desativar, realizamos uma operação AND com os bits de st[p] e o bit que queremos desativar negado.
			ll old = A[l];
            st[p] &= ~(1LL << (old-1));
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
	// A função __builtin_popcountll conta a quantidade de bits 1 em um long long.
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