#include <stdio.h>
#define MAX 512

int N;
int movX[] = {0,  0,  1, -1};
int movY[] = {1, -1,  0,  0};

char grid[MAX][MAX];

bool movValido(int i, int j){
    return i >= 0 && i < N && j >= 0 && j < N && grid[i][j] != '#';
}

int dfs(int i, int j){
    int count = 0;
    if(grid[i][j] == '*') count++;
    grid[i][j] = '#';
    for(int x = 0; x < 4; x++)
        if(movValido(i+movX[x], j+movY[x]))
            count += dfs(i+movX[x], j+movY[x]);
    return count;
}