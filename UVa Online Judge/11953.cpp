#include <iostream>
using namespace std;


char grid[112][112];

int n;

int movX[] = {1, -1, 0, 0};
int movY[] = {0, 0, 1, -1};

bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n && (grid[x][y] == 'x' || grid[x][y] == '@');
}

void dfs(int x, int y){
    grid[x][y] = '.';
    for(int i = 0; i < 4; i++){
        int newx = x + movX[i];
        int newy = y + movY[i];
        if(valid(newx, newy)){
            dfs(newx, newy);
        }
    }
}


int main(){
    
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'x'){
                    res++;
                    dfs(i, j);
                }
            }
        }
        cout << "Case " << tc << ": " << res << "\n";
    }
    return 0;
}