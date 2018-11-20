#include <cstdio>
#include <cmath>

int main(){
    int C;
    scanf("%d", &C);
    while(C--){
        int N;
        scanf("%d", &N);
        int quadradosPerfeitosDeUmAteN = floor(sqrt(N));
        printf("%d\n", N - quadradosPerfeitosDeUmAteN);
    }
    return 0;
}