/**
 *  URI 1895 - Jogo do Limite
 *  Felipe G. Foschiera - UPF
 */
#include <stdio.h>
#include <queue>
using namespace std;

inline int abs(int a){ return a < 0 ? -a : a; }


int main(){
    int N, T, L;
    scanf("%d %d %d", &N, &T, &L);
    queue<int> pilha;
    for(int i = 0; i < N-1; i++){
        int c;
        scanf("%d", &c);
        pilha.push(c);
    }
    int alice = 0, bob = 0;
    int turn = 0;
    for(int i = 0; i < N-1; i++){
        int card = pilha.front();
        pilha.pop();
        int diff = abs(T-card);
        if(diff <= L){
            if(!turn) alice += diff;
            else bob += diff;
            T = card;
        }
        turn ^= 1;
    }
    printf("%d %d\n", alice, bob);

    return 0;
}