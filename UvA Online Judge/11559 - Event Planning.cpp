// UvA 11559 - Event Planning
// Felipe G. Foschiera
#include <stdio.h>
#define INF ((int)1e9)

inline int min(int a, int b) { return a < b ? a : b; }

int main(){
    int N, B, H, W;
    while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
        int best_price = INF;
        for(int i = 0; i < H; i++){
            int preco, wk, ok = 0;
            scanf("%d", &preco);
            for(int j = 0; j < W; j++){
                scanf("%d", &wk);
                if(wk >= N) ok = 1;
            }
            preco *= N;
            if(ok && preco <= B){
                best_price = min(preco, best_price);
            }
        }
        if(best_price != INF){
            printf("%d\n", best_price);
        }else printf("stay home\n");
    }
    return 0;
} 