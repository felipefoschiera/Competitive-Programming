#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        int ans = 1 + (N * (1 + N)/ 2);
        printf("%d\n", ans);
    }
    return 0;
}