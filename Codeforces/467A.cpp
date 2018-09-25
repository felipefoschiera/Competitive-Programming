#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int count = 0, p, q;
    while(n--){
        scanf("%d %d", &p, &q);
        if(q-p >= 2) count++;
    }
    printf("%d\n", count);
    return 0;
}