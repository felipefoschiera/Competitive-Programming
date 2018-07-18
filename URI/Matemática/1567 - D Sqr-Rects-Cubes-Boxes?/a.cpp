#include <stdio.h>
typedef long long ll;

int main(){
    ll N;
    while(scanf("%lld", &N) != EOF){
        ll s2 = 0, s3 = 0, s4 = 0;
        for(ll i = 1; i <= N; i++){ 
            s2 += i*i;
            s3 += i*i*i;
            s4 += i*i*i*i;
        }
        ll r2 = N*N*(N+1)*(N+1) / 4;
        r2 -= s2;
        ll r3 = N*N*N*(N+1)*(N+1)*(N+1) / 8;
        r3 -= s3;
        ll r4 = N*N*N*N*(N+1)*(N+1)*(N+1)*(N+1) / 16;
        r4 -= s4;
        printf("%lld %lld %lld %lld %lld %lld\n", s2, r2, s3, r3, s4, r4);
    }
    return 0;
}