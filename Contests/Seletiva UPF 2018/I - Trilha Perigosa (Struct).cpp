#include <cstdio>
#include <vector>
#define MAX 55
using namespace std;

struct monstros {
	int count[MAX];
	monstros() { for(int i = 0; i < MAX; i++) count[i] = 0; }
	int distintos(){
		int cnt = 0;
		for(int i = 0; i < MAX; i++) if(count[i] > 0) cnt++;
		return cnt;
	}
};

/**
 * 	Nesta versão, ao invés de utilizar a bitmask, utilizamos uma struct chamada monstros
 * 	Que mantém um vetor com a quantidade de cada tipo de monstro naquele segmento.
 * 	A função distintos() retorn a quantidade de tipos que tem mais de 0 monstros, ou seja, existem.
 * 
 */

// Para unir segmentos, criamos uma nova struct com a soma das contagens dos vetores a serem somados.
monstros operator + (const monstros a, const monstros b){
	monstros c;
	for(int i = 0; i < MAX; i++) c.count[i] = a.count[i] + b.count[i];
	return c;		
}

class SegmentTree {
private:
	vector<monstros> st;
	vector<int> A;
	int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
	void build(int p, int l, int r){
		if(l == r){
			// Na hora da build, incrementamos no segmento a contagem do monstro de tipo A[l].
			st[p].count[A[l]]++;
		}else{
			build(left(p), l, (l+r)/2);
			build(right(p), (l+r)/2+1, r);
			st[p] = st[left(p)] + st[right(p)];
		}
	}
	void update(int p, int l, int r, int ind, int v){
		if(ind > r || ind < l) return;
		if(l == ind && r == ind){
			// Na hora da atualização, descontamos um monstro na contagem do antigo e incrementamos o novo.
			int old = A[l];
			st[p].count[old]--;
			A[l] = v;
			st[p].count[v]++;
		}else{
			update(left(p), l, (l+r)/2, ind, v);
			update(right(p), (l+r)/2+1, r, ind, v);
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
public:
	SegmentTree(vector<int> &_A){
		A = _A;
		size = A.size();
		st.assign(4*size, monstros());
		build(1, 0, size-1);
	}
	int update(int ind, int v) { update(1, 0, size-1, ind, v); }
	int query(int a, int b) { return query(1, 0, size-1, a, b).distintos(); }
};

int main(){
	int N, Q, M;
	while(scanf("%d %d %d", &N, &Q, &M) != EOF){
		vector<int> A(N);
		for(int i = 0; i < N; i++) scanf("%d", &A[i]);
		SegmentTree st(A);
		while(Q--){
			int op, l, r;
			scanf("%d %d %d", &op, &l, &r);
			if(op == 2){
				st.update(l-1, r);
			}else if(op == 1){
				printf("%d\n", st.query(l-1, r-1));
			}
		}
	}
	return 0;
}