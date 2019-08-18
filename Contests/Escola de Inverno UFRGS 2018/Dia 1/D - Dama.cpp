#include <stdio.h>
#include <stdlib.h>

int main(){
    int x1, y1, x2, y2;
    while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2), x1 != 0){
        printf("%d\n", (x1 == x2 && y1 == y2) ? 0 : 
            (x1 == x2 || y1 == y2) || abs(x1 - x2) == abs(y1 - y2) 
                ? 1 : 2);
    }
    return 0;
}
