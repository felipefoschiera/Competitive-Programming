#include <stdio.h>
#define MAX 112

int main(){
    int N;
    while(scanf("%d", &N), N){
        int m[MAX][MAX];
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(j == 1) m[i][j] = i;
                else if(j <= i) m[i][j] = m[i][j-1] - 1;
                else m[i][j] = m[i][j-1] + 1;
            }
        }
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                printf("%3d%c", m[i][j], j == N ? '\n' : ' ');
            
        printf("\n");
    }
    return 0;   
}