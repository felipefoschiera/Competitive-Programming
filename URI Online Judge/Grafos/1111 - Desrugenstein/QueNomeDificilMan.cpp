// URI 1111 - Desrugenstein
// Felipe G. Foschiera
#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f3f
#define MAX 15

int N;
int mat[MAX][4*MAX];

inline int min(int a, int b) { return a < b ? a : b; }

int AG[MAX][MAX][MAX][MAX];

bool ehValido(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }

int movX[] = {0,  0, -1, 1};
int movY[] = {1, -1,  0, 0};

void floydWarshall(){
    for(int k1 = 0; k1 < N; k1++)
        for(int k2 = 0; k2 < N; k2++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    for(int a = 0; a < N; a++)
                        for(int b = 0; b < N; b++)
                            AG[i][j][a][b] = min(AG[i][j][a][b], AG[i][j][k1][k2] + AG[k1][k2][a][b]);
                
}


int main(){
    while(scanf("%d", &N), N){
        memset(mat, 0, sizeof mat);
        for(int i = N-1; i >= 0; i--)
            for(int j = 0; j < 4*N; j++)
                scanf("%d", &mat[i][j]);
        memset(AG, INF, sizeof AG);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                AG[i][j][i][j] = 0;
                for(int x = 0; x < 4; x++){
                    int nY = i + movY[x], nX = j + movX[x];
                    if(ehValido(nY, nX) && mat[i][j*4+x] == 1)
                        AG[i][j][nY][nX] = 1; 
                }
            }
        floydWarshall();
        int P;
        scanf("%d", &P);
        int a, b, c, d;
        while(P--){
            scanf("%d %d %d %d", &a, &b, &c, &d);
            if(AG[b][a][d][c] != INF) printf("%d\n", AG[b][a][d][c]);
            else printf("Impossible\n");
        }
        printf("\n");
    }
    return 0;
}