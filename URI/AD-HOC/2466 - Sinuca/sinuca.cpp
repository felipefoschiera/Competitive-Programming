/**
 *  URI 2466 - Sinuca
 *  OBI 2014/Fase 2/Nível Junior
 *  Felipe G. Foschiera
 */
#include <stdio.h>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int bolas[N];
    for(int i = 0; i < N; i++){
        scanf("%d", bolas+i);
    }
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-1; j++){
            if(bolas[j] == bolas[j+1]){
                bolas[j] = 1;
            }else{
                bolas[j] = -1;
            }
        }
    }
    printf(bolas[0] == 1 ? "preta\n" : "branca\n");
    return 0;
}
