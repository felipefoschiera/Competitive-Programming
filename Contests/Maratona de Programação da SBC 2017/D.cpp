#include <stdio.h>
#define MAX 1000012
typedef long long ll;


int main(){
    ll N;
    scanf("%lld", &N);
    int divisores = 0;
    int i = 2;
    while(N > 1 && i < MAX){
        if(N % i == 0){
            divisores++;
            while(N % i == 0) N /= i;
        }
        i++;
    }    
    if(N != 1) divisores++;
    printf("%d\n", ((1 << divisores) - divisores - 1));
    return 0;
}