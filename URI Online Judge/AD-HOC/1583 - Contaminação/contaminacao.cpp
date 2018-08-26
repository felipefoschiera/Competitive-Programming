// URI 1583 - Contaminação
// Felipe G. Foschiera
#include <cstdio>
#define MAX 51

int N, M;
char mat[MAX][MAX];

bool movValido(int y, int x){
    return y >= 0 && y < N && x >= 0 && x < M && mat[y][x] == 'A';
}

int movX[] = {1, -1, 0,  0};
int movY[] = {0,  0, 1, -1};

void dfs(int y, int x){
    mat[y][x] = 'T';
    for(int i = 0; i < 4; i++){
        int nY = y + movY[i], nX = x + movX[i];
        if(movValido(nY, nX))
            dfs(nY, nX);
    }
}

int main(){
    while(scanf("%d %d", &N, &M), N+M){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                scanf(" %c", &mat[i][j]);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(mat[i][j] == 'T') dfs(i, j);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++)  
                printf("%c", mat[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;   
}