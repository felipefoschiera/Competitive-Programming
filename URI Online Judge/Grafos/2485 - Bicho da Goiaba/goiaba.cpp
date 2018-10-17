#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 112;
const int INF = 1e9;

int A, B;
int grid[MAX][MAX];
int dist[MAX][MAX];

int movY[] = {1, -1, 0,  0, 1, -1,  1, -1};
int movX[] = {0,  0, 1, -1, 1, -1, -1,  1};

bool movValido(int y, int x){
    return y >= 0 && y < A && x >= 0 && x < B && grid[y][x] == 1;
}

int bfs(int sy, int sx){
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            dist[i][j] = INF;
    int mx = 0;
    queue<pair<int, int> > fila;
    dist[sy][sx] = 0;
    fila.push({sy, sx});
    while(!fila.empty()){
        int y = fila.front().first;
        int x = fila.front().second;
        fila.pop();
        mx = max(mx, dist[y][x]);
        for(int i = 0; i < 8; i++){
            int ny = y + movY[i];
            int nx = x + movX[i];
            if(movValido(ny, nx)){
                if(dist[ny][nx] > dist[y][x] + 1){
                    dist[ny][nx] = dist[y][x] + 1;
                    fila.push({ny, nx});
                }
            }
        }
    }
    return mx;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &A, &B);
        for(int i = 0; i < A; i++)
            for(int j = 0; j < B; j++)
                scanf("%d", &grid[i][j]);
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;
        printf("%d\n", bfs(x, y));
    }
    return 0;
}