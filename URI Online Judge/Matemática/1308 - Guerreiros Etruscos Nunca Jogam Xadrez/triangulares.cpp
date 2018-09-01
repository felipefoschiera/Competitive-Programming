#include <cstdio>
#include <cmath>
typedef long long ll;


int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        ll N;
        scanf("%lld", &N);
        ll res = (sqrt(8*N + 1) - 1) / 2;
        printf("%lld\n", res);
    }
    return 0;
}