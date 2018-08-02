/**
 *  URI 2366 - Maratona
 *  Felipe G. Foschiera
 */
#include <stdio.h>

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int pos[N];
    scanf("%d", &pos[0]);
    bool can = true;
    for(int i = 1; i < N; i++){
        scanf("%d", pos+i);
        if(pos[i] - pos[i-1] > M){
            can = false;
        }
    }
    if(42195 - pos[N-1] > M){
        can = false;
    }
    printf(can ? "S\n" : "N\n");
    return 0;
}