#include <bits/stdc++.h>
using namespace std;
#define MAX 11234
#define INF ((int)2e9)

int main(){
    int D, tc, N, S, i, ans, cur;
    int f[MAX], t[MAX];
    scanf("%d", &D);
    for(tc = 1; tc <= D; tc++){
        scanf("%d %d", &N, &S);
        ans = -INF;
        for(i = 0; i < N; i++){
            scanf("%d %d", f+i, t+i);
            cur = (t[i] <= S) ? f[i] : (f[i] - (t[i] - S));
            if(i == 0 || ans < cur){
                ans = cur; 
            }
        }
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
