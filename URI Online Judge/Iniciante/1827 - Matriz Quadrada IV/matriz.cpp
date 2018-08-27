#include <cstdio>

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int mat[N][N];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                mat[i][j] = 0;

        for(int i = 0; i < N; i++)
           mat[i][i] = 2;
        for(int i = N-1; i >= 0; i--)
            mat[N-i-1][i] = 3;
        
        int mid = N/3;
        for(int i = mid; i < N-mid; i++){
            for(int j = mid; j < N-mid; j++)
                mat[i][j] = 1;
        }
        mat[N/2][N/2] = 4;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                printf("%d", mat[i][j]);
            }
            printf("\n");
        } 
        printf("\n");

    }
    return 0;
}