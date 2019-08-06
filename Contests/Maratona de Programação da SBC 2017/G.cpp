#include <stdio.h>
#include <string.h>
#define MAXT 51
#define MAXN 100123
#define MOD 1000000007
int T, M, N;

int dp[MAXT][MAXN];

int programa(int t, int n){
	if(n < M || n > N) return 0;
	if(dp[t][n] != -1) return dp[t][n];
	if(t <= 1) return dp[t][n] = t;
	return dp[t][n] = ((programa(t-1, n-1) % MOD) + (programa(t-1, n+1) % MOD)) % MOD;
}


int main(){

	scanf("%d %d %d", &T, &M, &N);
	memset(dp, -1, sizeof dp);
	int ans = 0;
	for(int i = M; i <= N; i++)
		ans = ((ans % MOD) + (programa(T, i) % MOD)) % MOD;
	printf("%d\n", ans);
	
	return 0;
}