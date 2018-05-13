#include <stdio.h>
#define INFTO ((int)1e9)
int main(){
    int N, M;
    int id, tempo;
    long long tempo_total, best = INFTO;
    scanf("%d %d", &N, &M); 
    for(int i = 1; i <= N; i++){
        tempo_total = 0;
        for(int j = 0; j < M; j++){
            scanf("%d", &tempo);
            tempo_total += tempo;
        }
        if(tempo_total < best){
            best = tempo_total;
            id = i;
        }
    }
    printf("%d\n", id);
    return 0;
}