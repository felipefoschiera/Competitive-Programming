/**
 *  URI 2337 - Pro Habilidade
 *  Felipe G. Foschiera
 */
#include <stdio.h>
typedef long long ll;

ll pow(int a, int b){
    if(b == 0) return 1;
    if(b&1) return a * pow(a, b-1);
    ll y = pow(a, b >> 1);
    return y * y;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 1) printf("1/1\n");
        else{
            ll denom = pow(2, n);
            ll num = 1, x = 1;
            for(int i = 0; i < n; i++){
                num += x;
                x = num - x;
            }
            ll mdc = gcd(num, denom);
            num /= mdc;
            denom /= mdc;
            printf("%lld/%lld\n", num, denom);
        }
    }
    return 0;
}