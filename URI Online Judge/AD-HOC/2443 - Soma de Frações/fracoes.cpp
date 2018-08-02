/**
 *  URI 2443 - Soma de Frações
 *  Felipe G. Foschiera
 */
#include <stdio.h>
using namespace std;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b){
    return a * b / mdc(a, b);
}

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int denom = mmc(b, d);
    int numerador = (denom / b * a) + (denom / d * c);
    int gcd = mdc(numerador, denom);
    printf("%d %d\n", numerador/gcd, denom/gcd);
    return 0;
}