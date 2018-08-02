/**
 *  URI 1699 - Jogo Entediante
 *  Felipe G. Foschiera - UPF
 */
#include <stdio.h>
#include <math.h>
typedef long long ll;

bool isPerfectSquare(ll n){
    ll root = sqrt(n);
    return root*root == n;
}

int main(){
    int n;
    while(scanf("%d", &n), n){
        ll ans = 0, x;
        for(int i = 0; i < n; i++){
            scanf("%lld", &x);
            ans += 2;
            if(isPerfectSquare(x)) ans--;
        }
        printf(ans&1 ? "Annie\n" : "Garen\n");
    }

    return 0;
}