#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
const int MAXT = 100;

typedef pair<int, int> ii;

char grid[MAX][MAX];
int occupy[MAX][MAX], n, m;

bool isValid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#';
}

// d1 = distancia do spread, d2 = distancia da personagem
int d1[MAX][MAX], d2[MAX][MAX];

int nX[] = {0, 0, 1, -1};
int nY[] = {1, -1, 0, 0};
const int INF = 0x3f3f3f3f;

void spread(queue<ii> &holes){
    while(!holes.empty()){
        ii pos = holes.front();
        holes.pop();
        for(int k = 0; k < 4; k++){
            int newx = pos.first + nX[k];
            int newy = pos.second + nY[k];
            if(isValid(newx, newy) && d1[newx][newy] > d1[pos.first][pos.second] + 1){
                d1[newx][newy] = d1[pos.first][pos.second] + 1;
                holes.push({newx, newy});
            }
        }
    }
}

void simulate(int x, int y){
    memset(d2, INF, sizeof d2);
    d2[x][y] = 0;
    queue<ii> q;
    q.push({x, y});
    while(!q.empty()){
        ii pos = q.front(); q.pop();
        for(int k = 0; k < 4; k++){
            int newx = pos.first + nX[k];
            int newy = pos.second + nY[k];
            if(isValid(newx, newy) && d2[newx][newy] > d2[pos.first][pos.second] + 1){
                d2[newx][newy] = d2[pos.first][pos.second] + 1;
                q.push({newx, newy});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        memset(d1, INF, sizeof d1);

        queue<ii> holes;
        ii start, endpos;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '*'){
                    d1[i][j] = 0;
                    holes.push({i, j});
                }else if(grid[i][j] == 'S'){
                    start = {i, j};
                }else if(grid[i][j] == 'X'){
                    endpos = {i, j};
                }
            }
        }
        spread(holes);
        simulate(start.first, start.second);
        bool can = d1[endpos.first][endpos.second] > d2[endpos.first][endpos.second];
        cout << (can ? "yes" : "no") << '\n';
    }
    return 0;
}