#include <stdio.h>
typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ll a, b;
    while(scanf("%lld %lld", &a, &b) != EOF){
        ll mdc = gcd(a, b);
        a /= mdc; b /= mdc;
        ll ans = a*2 + b*2;
        printf("%lld\n", ans);
    }
    return 0;
}