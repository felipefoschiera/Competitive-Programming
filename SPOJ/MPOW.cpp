// SPOJ MPOW - Power of matrix
// Felipe G. Foschiera
#include <cstdio>
#include <cassert>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

typedef vector<vector<ll> > matriz;

matriz operator * (matriz a, matriz b){
	int n = (int)a.size();
	int m = (int)b.size();
	int p = (int)b[0].size();
	assert(a[0].size() == b.size());
	matriz c;
	c.resize(n);
	for(int i = 0; i < n; i++){
		c[i].assign(p, 0);
		for(int j = 0; j < p; j++)
			for(int k = 0; k < m; k++){
				c[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
				c[i][j] %= MOD;
			}
	}
	return c;
}

matriz id(int size){
	matriz c(size, vector<ll>(size, 0));
	for(int i = 0; i < size; i++)
		c[i][i] = 1;
	return c;
}

matriz matrizExp(matriz a, int n){
	if(n == 0) return id(a.size());
	matriz c = matrizExp(a, n>>1);
	c = c*c;
	if(n&1) c = c*a;
	return c;
}


int main(){	
	int T;
	scanf("%d", &T);
	while(T--){
		int M;
		ll N;
		scanf("%d %lld", &M, &N);
		matriz mat(M, vector<ll>(M));
		for(int i = 0; i < M; i++)
			for(int j = 0; j < M; j++)
				scanf("%lld", &mat[i][j]);
		mat = matrizExp(mat, N);
		for(int i = 0; i < M; i++){
			for(int j = 0; j < M; j++){
				printf("%lld%c", mat[i][j], (j == M-1 ? '\n': ' '));
			}
		}
	}
	return 0;
}

