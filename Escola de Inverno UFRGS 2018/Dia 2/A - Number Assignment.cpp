#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#include <algorithm>
using namespace std;
#define MAX 112

typedef long long ll;

int N;
ll a[MAX], dp[MAX][MAX][MAX];


int main(){
    int T, M, tc, i;
    ll ans, maximo;
    scanf("%d", &T);
    for(tc = 1; tc <= T; tc++){
        scanf("%d %d", &N, &M);
        for(i = 0; i < N; i++){
            scanf("%lld", a+i);
        }
        sort(a, a+N);
  
        memset(dp, -1LL, sizeof(dp));
        
        for(int m = 1; m <= M; m++){
            for(int i = 0; i < N; i++){
                for(int j = i; j < N; j++){
                    if(m == 1) dp[m][i][j] = a[j] - a[i];
                    else {
                        maximo = a[N-1] - a[0];
                        for(int k = i; k < j; k++){
                            maximo = min(maximo, (a[k] - a[i]) + dp[m-1][k+1][j]);
                        }
                        dp[m][i][j] = maximo;   
                    }
                }
            }

        }
        ans = dp[M][0][N-1];
        assert(ans <= a[N-1] - a[0]);
        printf("Case #%d: %lld\n", tc, ans);
    }
    return 0;
}
