#include <stdio.h>

int main(){
    int k, n, w;
    scanf("%d %d %d", &k, &n, &w);
    int ans = (w + w*w) / 2 * k;
    ans -= n;
    printf("%d\n", ans > 0 ? ans : 0);

    return 0;
}
