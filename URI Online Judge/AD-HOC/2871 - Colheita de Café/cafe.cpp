#include <cstdio>

int main(){
    int M, N;
    while(scanf("%d %d", &M, &N) != EOF){
        int soma = 0, v;
        for(int i = 0; i < M; i++) for(int j = 0; j < N; j++) {
            scanf("%d", &v);
            soma += v;
        }
        int sacas = soma / 60;
        int litros = soma % 60;
        printf("%d saca(s) e %d litro(s)\n", sacas, litros);
    }
    return 0;
}