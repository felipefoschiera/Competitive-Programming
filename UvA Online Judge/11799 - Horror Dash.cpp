// UvA 11799 - Horror Dash
// Felipe G. Foschiera
#include <stdio.h>
int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        int N, v, best = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d", &v);
            best = (v > best) ? v : best;
        }
        printf("Case %d: %d\n", t, best);
    }
    return 0;
}