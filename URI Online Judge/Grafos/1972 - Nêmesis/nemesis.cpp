// URI 1972 - Nêmesis
// Felipe G. Foschiera
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
const int MAX = 512;
typedef pair<int, pair<int, int> > iii;

int N, M;
int dist[MAX][MAX];
char grid[MAX][MAX];


int movX[] = {1, -1, 0,  0};
int movY[] = {0,  0, 1, -1};


bool movValido(int y, int x){
    return y >= 0 && y < N && x >= 0 && x < M && grid[y][x] != '#';
}

int dijkstra(int sy, int sx){
    memset(dist, INF, sizeof dist);
    dist[sy][sx] = 0;
    priority_queue<iii, vector<iii>, greater<iii>> q;
    q.push({0, {sy, sx}});
    while(!q.empty()){
        int y = q.top().second.first;
        int x = q.top().second.second;
        q.pop();
        if(grid[y][x] == 'E') return dist[y][x];
        for(int i = 0; i < 4; i++){
            int ny = y + movY[i];
            int nx = x + movX[i];
            if(movValido(ny, nx)){
                int w = grid[ny][nx] >= '0' && grid[ny][nx] <= '9' ? grid[ny][nx] - '0' : 0;
                if(dist[ny][nx] > dist[y][x] + w){
                    dist[ny][nx] = dist[y][x] + w;
                    q.push({dist[ny][nx], {ny, nx}});
                }
            }   
        }
    }   
    return -1;
}

int main(){
    while(scanf("%d %d", &N, &M) != EOF){
        int sy = -1, sx = -1;
        for(int i = 0; i < N; i++){
            scanf(" %s", &grid[i]);
            for(int j = 0; grid[i][j]; j++){
                if(grid[i][j] == 'H') { sy = i, sx = j; }
            }
        }
        int ans = dijkstra(sy, sx);
        if(ans == -1) printf("ARTSKJID\n");
        else printf("%d\n", ans);
    }
    return 0;
}