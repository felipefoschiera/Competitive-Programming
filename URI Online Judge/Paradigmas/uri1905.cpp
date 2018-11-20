// URI 1905 - Polícia e Ladrão
// Felipe G. Foschiera
// Resolvido com Flood-Fill
#include <stdio.h>

int mat[5][5];

bool movValido(int i, int j){
    return i >= 0 && i < 5 && j >= 0 && j < 5 && mat[i][j] != 1;
}

int movX[] = {1, -1, 0,  0};
int movY[] = {0,  0, 1, -1};

void dfs(int i, int j){
    mat[i][j] = 1;
    for(int x = 0; x < 4; x++)
        if(movValido(i+movX[x], j+movY[x]))
            dfs(i+movX[x], j+movY[x]);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                scanf("%d", &mat[i][j]);    
        dfs(0, 0);
        printf("%s\n", mat[4][4] == 1 ? "COPS" : "ROBBERS");
    }
    return 0;
}