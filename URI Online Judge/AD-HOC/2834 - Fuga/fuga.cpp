#include <cstdio>
#define MAX 15

inline int max(int a, int b){ return a > b ? a : b; }

int N, M, xe, ye, xs, ys;
int grid[MAX][MAX], ans, cost;

bool movValido(int i, int j){
    return i >= 1 && j >= 1 && i <= N && j <= M && grid[i][j] == 0;
}

int movX[] = {2, -2, 0, 0};
int movY[] = {0,  0, 2, -2};


int dfs(int x, int y){
    grid[x][y] = 1;
    cost++;
    if(x == xs && y == ys) ans = max(ans, cost);
    else {
        for(int i = 0; i < 4; i++){
            int nx = x + movX[i], ny = y + movY[i];
            if(movValido(nx, ny)){
                cost++;
                dfs(nx, ny);
                cost--;
            }
        }
    }
    cost--;
    grid[x][y] = 0;
}

int main(){
    while(scanf("%d %d", &N, &M) != EOF){
        scanf("%d %d %d %d", &xe, &ye, &xs, &ys);
        for(int i = 2; i <= N; i += 2)
            for(int j = 2; j <= M; j += 2)
                grid[i][j] = 1;
    ans = 0, cost = 0;
    dfs(xe, ye);
    printf("%d\n", ans);
    }
    return 0;
}