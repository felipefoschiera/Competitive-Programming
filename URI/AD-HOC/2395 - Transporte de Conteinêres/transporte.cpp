/**
 * URI 2395 - Transporte de Contêineres
 * Felipe G. Foschirea
 */
#include <stdio.h>
int main(){
    int A, B, C, X, Y, Z;
    scanf("%d %d %d", &A, &B, &C);
    scanf("%d %d %d", &X, &Y, &Z);
    long long total;
    if(A > X || B > Y || C > Z)
        total = 0;
    else
        total = (X / A) * (Y / B) * (Z / C);
    
    printf("%lld\n", total);
    return 0;
}