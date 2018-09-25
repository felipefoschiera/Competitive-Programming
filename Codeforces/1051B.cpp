#include <cstdio>
typedef long long ll;


int main(){
    ll l, r;
    while(scanf("%lld %lld", &l, &r) != EOF){
        ll interval = (r - l + 1);
        ll pairs = interval / 2;
        if((r-l)%2==0) printf("NO\n");
        else {
            printf("YES\n");
                for(ll k = l; k <= r; k += 2){
                    printf("%lld %lld\n", k, k+1);
                }
        }
    }
    return 0;
}