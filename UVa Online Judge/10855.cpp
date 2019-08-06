#include <iostream>
using namespace std;




int res[4];

char grid[1010][1010];
char pat[1010][1010];

void busca(int N, int n, int idx){
    for(int i = 0; i <= N-n; i++){
        for(int j = 0; j <= N-n; j++){
            bool ok = true;
            for(int a = 0; a < n; a++){
                for(int b = 0; b < n; b++){
                    if(grid[i+a][j+b] != pat[a][b]){
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            res[idx] += ok;
        }
    }
}


void rotate(int n){
    char tmp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tmp[j][n-i-1] = pat[i][j];
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            pat[i][j] = tmp[i][j];
}

int main(){
    int N, n;
    while(cin >> N >> n, N+n){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> grid[i][j];
        for(int i = 0; i < 4; i++) res[i] = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> pat[i][j];
        for(int i = 0; i < 4; i++){
            busca(N, n, i);
            rotate(n);
        }
        for(int i = 0; i < 4; i++){
            cout << res[i] << (i==3 ? '\n' : ' ');
        }
    }
    return 0;
}