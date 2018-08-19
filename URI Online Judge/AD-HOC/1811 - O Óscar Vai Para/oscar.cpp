#include <cstdio>
#define MAXN 1123
#define MAXM 112

int main(){
    int mat[MAXN][MAXM];
    int n, m, tc = 1;
    while(scanf("%d", &n), n){
        int best_i = 0, max_seq = 1, best_end = 0;
        scanf("%d", &m);
        printf("Instancia #%d\n", tc++);
        if(m == 0) printf("1\n\n");
        else {
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++)
                    scanf("%d", &mat[i][j]);

                for(int j = 0; j < m; j++){
                    int it = j;
                    while(it < m-1 && mat[i][it+1] > mat[i][it]) it++;

                    int best_start = best_end - max_seq + 1, sz = it - j + 1;
                    if(sz > max_seq){
                        max_seq = sz, best_i = i, best_end = it;
                    }else if(sz == max_seq){
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