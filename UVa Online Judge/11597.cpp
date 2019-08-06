#include <stdio.h>

int main(){
    int n, tc = 1;
    while(scanf("%d", &n), n){
        printf("Case %d: %d\n", tc++, n/2);
    }
    return 0;
}