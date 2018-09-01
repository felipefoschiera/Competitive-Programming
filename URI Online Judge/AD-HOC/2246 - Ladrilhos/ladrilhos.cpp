#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 212
#define INF ((int)1e9)
using namespace std;
typedef pair<int, int> ii;

int H, L;
int movX[] = {1, -1, 0,  0};
int movY[] = {0,  0, 1, -1};
int mat[MAX][MAX], visited[MAX][MAX];

bool valido(ii a, ii b){
    return b.first >= 0 && b.first < H && b.second >= 0 && b.second < L && 
    mat[b.first][b.second] == mat[a.first][a.second] && (!visited[b.first][b.second]);
}

int bfs(int sty, int stx){
    int count = 0;
    queue<ii> fila;
    visited[sty][stx] = 1;
    fila.push({sty, stx});
    while(!fila.empty()){
        int y = fila.front().first, x = fila.front().second;
        fila.pop();
        count++;
        for(int i = 0; i < 4; i++){
            int nY = y + movY[i], nX = x + movX[i];
            if(valido({y, x}, {nY, nX})){
                visited[nY][nX] = 1;            
                fila.push({nY, nX});
            }
        }
    }
    return count;
}


int main(){
    while(scanf("%d %d", &H, &L) != EOF){
        memset(visited, 0, sizeof visited);
        for(int i = 0; i < H; i++)
            for(int j = 0; j < L; j++)
                scanf("%d", &mat[i][j]);
        int best = INF;
        for(int i = 0; i < H; i++)
            for(int j = 0; j < L; j++){
                if(!visited[i][j])
                    best = min(best, bfs(i, j));
            }
        printf("%d\n", best);
    }
    return 0;
}