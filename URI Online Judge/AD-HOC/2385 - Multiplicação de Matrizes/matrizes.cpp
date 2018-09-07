// URI 2385 - Multiplicação de Matrizes
// Felipe G. Foschiera
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;


ll matrixMult(vector<ll> &A, vector<ll> &B){
	int m = B.size();
	ll res = 0LL;
	for(int k = 0; k < m; k++)
		res += A[k] * B[k];
	return res;
}


int main(){
	int N, P, Q, R, S, X, Y;
	while(scanf("%d", &N) != EOF){
		scanf("%d%d%d%d%d%d", &P, &Q, &R, &S, &X, &Y);
		int linha, coluna;
		scanf("%d%d", &linha, &coluna);
		vector<ll> A(N, 0);
		for(int j = 1; j <= N; j++){
			A[j-1] = (P * linha + Q * j) % X;
		}
		vector<ll> B(N, 0);
		for(int i = 1; i <= N; i++){
			B[i-1] = (R * i + S * coluna) % Y;
		}
		ll res = matrixMult(A, B);
		printf("%lld\n", res);
	}
	return 0;
}