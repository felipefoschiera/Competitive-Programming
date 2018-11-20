#include <cstdio>

const int MAX = 1123;

int N, M;
char cell[MAX][MAX];

int movX[] = {-1,  0,  1, -1, 1, -1, 0, 1};
int movY[] = {-1, -1, -1,  0, 0,  1, 1, 1};

bool ehTropa(int i, int j){
    return i >= 1 && i <= N && j >= 1 && j <= M && cell[i][j] == 'T';
}

int countNearby(int i, int j){
    int res = 0;
    for(int k = 0; k < 8; k++){
        res += ehTropa(i+movX[k], j+movY[k]);
    }
    return res;
}

int main(){
    int C;
    scanf("%d", &C);
    while(C--){
        int P;
        scanf("%d %d %d", &N, &M, &P);
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                scanf(" %c", &cell[i][j]);
        int y, x;
        while(P--){
            scanf("%d %d", &y, &x);
            printf("%s\n", countNearby(y, x) >= 5 ? "GRRR" : "GG IZI");
        }   
    }
    return 0;
}