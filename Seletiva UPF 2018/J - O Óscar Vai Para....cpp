#include <cstdio>
#define MAXN 1123
#define MAXM 112

/**
 * Para resolver este problema, buscamos em cada ator qual é sua maior sequência crescente de batimentos.
 * Mantemos junto com o tamanho da maior sequência o índice do seu fim, para podermos então
 * verificar os pontos de desempate tendo o fim e o início, que é igual a (fim - tamanho + 1).
 * 
 */

int main(){
    int N, M, mat[MAXN][MAXM], tc = 1;
    while(scanf("%d", &N), N){
        int best_i = 0, max_seq = 1, best_end = 0;
        scanf("%d", &M);
        printf("Instancia #%d\n", tc++);
        if(M == 0) printf("1\n\n");
        else {
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++)
                    scanf("%d", &mat[i][j]);

                for(int j = 0; j < M; j++){
                    int it = j;
                    while(it < M-1 && mat[i][it+1] > mat[i][it]) it++;

                    int best_start = best_end - max_seq + 1;
                    int sz = it - j + 1;
                    if(sz > max_seq)
                        max_seq = sz, best_i = i, best_end = it;
                    else if(sz == max_seq){
                        int diff = mat[i][it] - mat[i][j];
                        int best_diff = mat[best_i][best_end] - mat[best_i][best_start];
                        if(diff > best_diff)
                            best_i = i, best_end = it;
                        else if(diff == best_diff){
                            if(mat[i][it] > mat[best_i][best_end])
                                best_i = i, best_end = it;
                            
                        }
                    }
                }
            }
            printf("%d\n\n", best_i+1);
        }
    }
    return 0;
}