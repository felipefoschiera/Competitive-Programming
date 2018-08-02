#include <stdio.h>

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%c\n", a > b ? '>' : a == b ? '=' : '<');
    }
    return 0;
}