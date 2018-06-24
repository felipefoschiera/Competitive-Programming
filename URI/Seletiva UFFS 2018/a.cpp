/**
 *  Seletiva UFFS 2018 - URI Online Judge
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#define enf 1e-9

int main(){
    int n;
    scanf("%d", &n);
    double a, b, ans = 0.0;
    while(n--){
        scanf("%lf %lf", &a, &b);
        ans += a / b;
    }
    printf(ans + enf > 1.0 + enf ? "FAIL\n" : "OK\n");
    return 0;
}