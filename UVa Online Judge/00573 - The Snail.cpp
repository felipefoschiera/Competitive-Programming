// UvA 00573 - The Snail
// Felipe G. Foschiera
#include <stdio.h>
int main(){
    double H, U, D, F;
    while(scanf("%lf %lf %lf %lf", &H, &U, &D, &F), H){
        int day = 1; 
        double altura = 0, decrease = F * U / 100.0;
        while(altura >= 0 && altura <= H){
            altura += U;
            if(altura > H) break;
            if(U > 0) U -= decrease;
            altura -= D;
            if(altura < 0) break;
            day++;
        }
        printf("%s on day %d\n",(altura < 0 ? "failure" : "success") , day);
    }
    return 0;
}