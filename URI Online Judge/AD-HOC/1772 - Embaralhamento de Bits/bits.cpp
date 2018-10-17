#include <cstdio>

int main(){
    unsigned N, K, A, B;
    while(scanf("%u %u", &N, &K), N+K){
        unsigned min = N, max = N;
        while(K--){
            scanf("%u %u", &A, &B);
            unsigned bitA = N & (1 << A);
            unsigned bitB = N & (1 << B);
            if(bitA) N |= (1 << B);
            else N &= ~(1 << B);
            if(bitB) N |= (1 << A);
            else N &= ~(1 << A);
            if(N > max) max = N;
            if(N < min) min = N;
        }
        printf("%u %u %u\n", N, max, min);
    }
    return 0;
}