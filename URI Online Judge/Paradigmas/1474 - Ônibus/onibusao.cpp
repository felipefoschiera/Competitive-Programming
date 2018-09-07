#include <cstdio>
#include <vector>
#define MOD ((int)1e6)
using namespace std;
typedef long long ll;

typedef vector<vector<ll> > matriz;

matriz operator * (matriz a, matriz b){
	int n = (int)a.size();
	int m = (int)b.size();
	int p = (int)b[0].size();
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

matriz exponencial(matriz m, ll expo){
	if(expo == 0) return {{1, 0}, {0, 1}};
	matriz ret = exponencial(m, expo>>1);
	ret = ret * ret;
	if(expo&1) ret = ret * m;
	return ret;
}


int main(){	
	ll N, K, L;
	while(scanf("%lld %lld %lld", &N, &K, &L) != EOF){
		N /= 5;
		K %= MOD;
		L %= MOD;
		matriz mat = {{0, L}, {1, K}}; 
		mat = exponencial(mat, N);
		matriz base = {{1, K}, {1, 0}};
		base  = base * mat;
		printf("%06lld\n", base[0][0] % MOD);
	}
	return 0;
}

