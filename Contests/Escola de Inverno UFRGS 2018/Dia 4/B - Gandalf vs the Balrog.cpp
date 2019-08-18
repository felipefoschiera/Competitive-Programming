#include <stdio.h>
#include <string.h>

const int MAX = 1123456;

bool marcado[MAX];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M, x, y;
        scanf("%d %d", &N, &M);
        memset(marcado, false, sizeof marcado);
        for(int i = 0; i < M; i++){
            scanf("%d %d", &x, &y);
            marcado[y] = true;
        }
        if(!marcado[N]){
            printf("2 %d\n", N);
        }else{
            bool ok = true;
            for(int i = N-1; i > 0; i--){
                if(!marcado[i]){
                    ok = false;
                    printf("1\n");
                    break;
                }
            }
            if(ok) printf("0\n");
            
        }
        
    
    }

    return 0;
}