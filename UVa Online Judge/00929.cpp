#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int grid[1010][1010];
int dist[1010][1010];
const int INF = 0x3f3f3f3f;

int movX[] = {1, -1, 0, 0};
int movY[] = {0, 0, 1, -1};

int n, m;

bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

typedef pair<int, pair<int, int>> ii;
int dijkstra(int sx, int sy){
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, {sx, sy}});
    dist[sx][sy] = grid[sx][sy];

    while(!pq.empty()){
        ii u = pq.top();
        pq.pop();
        if(u.first > dist[u.second.first][u.second.second]) continue;
        for(int i = 0; i < 4; i++){
            int nx = u.second.first + movX[i];
            int ny = u.second.second + movY[i];
            if(valid(nx, ny) && dist[nx][ny] > dist[u.second.first][u.second.second] + grid[nx][ny]){
                dist[nx][ny] = dist[u.second.first][u.second.second] + grid[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }
    return dist[n-1][m-1];
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        memset(dist, INF, sizeof dist);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> grid[i][j];
        cout << dijkstra(0, 0) << "\n";
    }
    return 0;
}