/**
 *  URI 2317 - Lobo Mau
 *  Felipe G. Foschiera - UPF
 */
#include <stdio.h>
#include <vector>
#define MAX 251
using namespace std;
typedef pair<int, int> ii;

int R, C;
int movX[] = {0, 0, 1, -1};
int movY[] = {1, -1, 0, 0};

char grid[MAX][MAX];

bool movValido(int i, int j){
    return i >= 0 && i < R && j >= 0 && j < C && grid[i][j] != '#';
}

ii operator + (const ii a, const ii b){
    return ii(a.first + b.first, a.second + b.second);
}

ii dfs(int i, int j){
    ii count = ii(0, 0);
    if(grid[i][j] == 'v') count.second++;
    if(grid[i][j] == 'k') count.first++;
    grid[i][j] = '#';
    for(int x = 0; x < 4; x++)
        if(movValido(i+movX[x], j+movY[x]))
            count = count + dfs(i+movX[x], j+movY[x]);
    return count;
}

int main(){
    scanf("%d %d", &R, &C);
    int ovelhas = 0, lobos = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf(" %c", &grid[i][j]);
            if(grid[i][j] == 'k') ovelhas++;
            else if(grid[i][j] == 'v') lobos++;
        }
    }
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(grid[i][j] == '.' || grid[i][j] == 'v' || grid[i][j] == 'k'){
                ii ans = dfs(i, j);
                if(ans.first > ans.second) lobos -= ans.second;
                else ovelhas -= ans.first;
            }
   
    printf("%d %d\n", ovelhas, lobos);
    return 0;
}