// URI 2505 - Autopotencial
// Felipe G. Foschiera
#include <cstdio>

typedef long long ll;

ll power(ll a, ll b, int MOD){
	if(b == 0) return 1;
    if(b&1) return (a * power(a, b-1, MOD)) % MOD;
    ll c = power(a, b >> 1, MOD);
    return (c*c) % MOD;
}
int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int len = 0, mod = 10;
        for(int cp = N; cp; cp /= 10) len++;
        for(int i = 0; i < len-1; i++) mod *= 10;
        ll res = power(N, N, mod);
        printf("%s\n", res == N ? "SIM" : "NAO");
    }
    return 0;
}