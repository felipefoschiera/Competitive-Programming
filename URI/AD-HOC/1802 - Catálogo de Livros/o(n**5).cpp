/**
 *  URI 1802 - Catálogo de Livros
 *  Felipe G. Foschiera - UPF
 */
#include <stdio.h>
#include <algorithm>
using namespace std;

bool comp(const int a, const int b){ return a > b; }

int main(){
    int livros[5][11];
    int P, M, F, Q, B;
    for(int i = 0; i < 5; i++){
        int x;
        scanf("%d", &x);
        if(i == 0) P = x;
        if(i == 1) M = x;
        if(i == 2) F = x;
        if(i == 3) Q = x;
        if(i == 4) B = x;
        for(int j = 0; j < x; j++) scanf("%d", livros[i]+j);
    }
    int sz = P*M*F*Q*B;
    int valores[sz];
    int ind = 0;
    for(int a = 0; a < P; a++)
        for(int b = 0; b < M; b++)
            for(int c = 0; c < F; c++)
                for(int d = 0; d < Q; d++)
                    for(int e = 0; e < B; e++){
                        valores[ind] = livros[0][a] + livros[1][b] + livros[2][c] + livros[3][d] + livros[4][e];
                        ind++;
                    }
    sort(valores, valores+sz, comp);
    int k;
    scanf("%d", &k);
    int sum = 0;
    for(int i = 0; i < k; i++) sum += valores[i];
    printf("%d\n", sum);



    return 0;
}