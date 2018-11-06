#include <cstdio>

typedef long long ll;

int main(){
    ll a, b;
    while(scanf("%lld %lld", &a, &b) != EOF){
        int years = 0;
        do {
            years++;
            a *= 3, b *= 2;
        }while(a <= b);
        printf("%d\n", years);
    }

    return 0;
}