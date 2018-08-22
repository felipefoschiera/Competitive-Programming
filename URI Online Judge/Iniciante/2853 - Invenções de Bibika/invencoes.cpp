#include <iostream>
#include <vector>
#define MAX 1123
using namespace std;

int N, M;
int mat[MAX][MAX];

bool movValido(int y, int x){
    return y >= 0 && y < N && x >= 0 && x < M && mat[y][x] == 0;
}

int main(){
    while(cin >> N >> M){
        vector<int> x, y;
        char c;
        int total = 0, cnt_robos = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> c;
                if(c == '@') {
                    mat[i][j] = 1; total++; cnt_robos++;
                    x.push_back(j); y.push_back(i);
                }else if(c == '#') mat[i][j] = 0;
            }
        }
        int movX[] = {1, -1, 0,  0};
        int movY[] = {0,  0, 1, -1};
        int dia = 0;
        bool ok = true;
        int inteiro = N*M;
        
        if(cnt_robos != inteiro){
            while(true){
                for(int k = 0; k < cnt_robos; k++){
                    for(int z = 0; z < 4; z++){
                        int nx = x[k] + movX[z], ny = y[k] + movY[z];
                        if(movValido(ny, nx)){
                            mat[ny][nx] = 1;
                            total++;
                        }
                    }
                }
                dia++;
                movX[0]++, movX[1]--;
                movY[2]++, movY[3]--;

                if(total >= (N*M)) { ok = true; break;}
                if(dia >= MAX) { ok = false; break; }
            }
        }
        printf("%d\n", ok ? dia : -1);        

    }
    return 0;
}
