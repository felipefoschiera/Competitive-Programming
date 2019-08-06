#include <stdio.h>
typedef long long ll;

ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


int main(){
    int N, L;
    while(scanf("%d %d", &N, &L) != EOF){
        ll ciclos = 1, v;
        for(int i = 0; i < N; i++){
            scanf("%lld", &v);
            ciclos = lcm(ciclos, v);
        }
        ll best = ciclos;
        int best_it = 1;
        for(int it = 2; it <= L; it++){
            ll simul = lcm(ciclos, it);
            if(simul > best && simul <= L){
                best = simul;
                best_it = it;
            }
        }
        printf("%d\n", best_it);
    }
    
    return 0;
}