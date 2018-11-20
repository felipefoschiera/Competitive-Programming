// URI 1839 - A Câmara Secreta
// Felipe G. Foschiera
#include <cstdio>

const int MOD = 1e9+7;
const int MAX = 2510;

int P[MAX][MAX];

void pascal(){
    for(int i = 0; i < MAX; i++){
        P[i][0] = 1;
        P[i][i] = 1;
        for(int j = 0; j < i; j++){
            P[i][j] = (P[i-1][j-1] + P[i-1][j]) % MOD;
        }
    }
}

const int MAXN = 55;

char mat[MAXN][MAX];

int main(){
    pascal();
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf(" %s", mat[i]);
    int xa, ya, xb, yb;
    while(scanf("%d %d %d %d", &xa, &ya, &xb, &yb) != EOF){
        xa--, ya--, xb--, yb--;
        int cnt = 0;
        int szx = xb - xa + 1;
        int szy = yb - ya + 1;
        int dim = szx*szy;
        for(int i = xa; i <= xb; i++){
            for(int j = ya; j <= yb; j++){
                cnt += (mat[i][j] == '#');
            }
        }
        int res = P[dim][cnt] - 1;
        printf("%d\n", res);
    }
    return 0;
}