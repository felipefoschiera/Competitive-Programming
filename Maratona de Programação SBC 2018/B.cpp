#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#define MAX 112
#define MAXX 200
using namespace std;

int pd[MAX][MAX];

bool valido(int i, int j){
    return i > 0 && j > 0 && i != j;
}

int solve(int i, int j){
    if(pd[i][j] != -1) return pd[i][j];
    if((i == 1 && j == 2) || (i == 2 && j == 1)) return pd[i][j] = 0;
    int visited[MAXX];
    memset(visited, 0, sizeof visited);
    for(int x = 1; x <= i; x++)
        if(valido(i-x, j))
            visited[solve(i-x, j)] = 1;
    for(int x = 1; x <= j; x++)
        if(valido(i, j-x))
            visited[solve(i, j-x)] = 1;
    for(int x = 1; x <= min(i, j); x++)
        if(valido(i-x, j-x))
            visited[solve(i-x, j-x)] = 1;
    for(int x = 0; x < MAXX; x++)
        if(!visited[x])
            return pd[i][j] = x;
    return -1;
}

int main(){
    int N, l, c, res = 0;
    scanf("%d", &N);
    memset(pd, -1, sizeof pd);
    bool startWin = false;
    for(int i = 0; i < N; i++){
        scanf("%d %d", &l, &c);
        if(l == c) {
            startWin = true; break;
        }
        res ^= solve(l, c);
    }
    if(startWin) printf("Y\n");
    else printf("%c\n", res ? 'Y' : 'N');
    return 0;
}