#include <stdio.h>

int main(){
    int K;
    while(scanf("%d", &K), K){
        int sx, sy;
        scanf("%d %d", &sx, &sy);
        for(int i = 0; i < K; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            if(x == sx || y == sy) printf("divisa\n");
            else {
                if(x > sx){
                    if(y > sy) printf("NE\n");
                    else printf("SE\n");
                }else{
                    if(y < sy) printf("SO\n");
                    else printf("NO\n");
                }
            }
        }
    }
    return 0;
}