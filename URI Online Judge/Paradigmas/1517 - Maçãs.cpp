#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pos;


const int MAXN = 25;
const int MAXK = 1123;

int N, M, K;
int maxtime;

int maca[MAXN][MAXN][MAXK];
int dp[MAXN][MAXN][MAXK];

int movX[] = {1,  1, 1, 0, -1, -1, -1,  0};
int movY[] = {-1, 0, 1, 1,  1,  0, -1, -1};

bool valid(ii point){
    return point.first > 0 && point.second > 0 && point.first <= N && point.second <= M;
}

int solve(ii curpos, int curtime){
    // verifica se o tempo máximo chegou ou se já analisou o estado
    if(curtime == maxtime) return 0;
    if(dp[curpos.first][curpos.second][curtime] != -1)
        return dp[curpos.first][curpos.second][curtime];

    // conta as maças naquela posição e tempo
    int macas = maca[curpos.first][curpos.second][curtime];
    // define a resposta base como ficar parado
    int res = macas + solve(curpos, curtime+1);
    // testa as 8 posições adjacentes buscando a melhor solução
    for(int i = 0; i < 8; i++){
        ii v = {curpos.first + movX[i], curpos.second + movY[i]};
        if(valid(v)){
            res = max(res, macas + solve(v, curtime+1));
        }
    }
    return dp[curpos.first][curpos.second][curtime] = res;
}

int main(){
    while(scanf("%d %d %d", &N, &M, &K), N+M+K){
        maxtime = 0;
        memset(maca, 0, sizeof maca);
        int x, y, t;
        // lê as posições e determina o tempo máximo
        for(int i = 0; i < K; i++){
            scanf("%d %d %d", &x, &y, &t);
            maca[x][y][t] = 1;
            if(t+1 > maxtime) maxtime = t+1;
        }
        // lê a posição inicial e inicializa a tabela dp
        ii start;
        scanf("%d %d", &start.first, &start.second);
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(start, 0));
    }
    return 0;
}
