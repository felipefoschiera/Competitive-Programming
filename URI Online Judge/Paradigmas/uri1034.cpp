#include <cstdio>
#include <cstring>
#define INF ((int)1e9)

const int MAXN = 30;
const int MAXM = 1010101;

inline int min(int a, int b) { return a < b ? a : b; }

int N, M;
int pd[MAXM], blocos[MAXN];

int solve(int M){
    if(M < 0) return INF;
    if(M == 0) return 0;
    if(pd[M] != -1)
        return pd[M];
    int res = INF;
    for(int i = 0; i < N; i++){
        res = min(res, 1 + solve(M-blocos[i]));
    }
    return pd[M] = res;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++){
            scanf("%d", &blocos[i]);
        }
        memset(pd, -1, sizeof pd);
        printf("%d\n", solve(M));
    }
    return 0;
}
