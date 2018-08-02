/**
 *  URI 1063 - Trilhos Novamente... Traçando Movimentos
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <stack>
#define MAX 27
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n), n){
        int v[MAX], target[MAX];
        char c;
        for(int i = 0; i < n; i++){
            scanf(" %c", &c);
            v[i] = c - 'a';
        }
        for(int i = 0; i < n; i++){
            scanf(" %c", &c);
            target[i] = c - 'a';
        }
        int ind = 0;
        stack<int> pilha;
        for(int i = 0; i < n; i++){
            pilha.push(v[i]);
            printf("I");
            if(pilha.top() == target[ind]){
                while(pilha.top() == target[ind]){
                    pilha.pop();
                    ind++;
                    printf("R");
                    if(pilha.empty()) break;
                }
            }
        }
        if(ind != n) printf(" Impossible");
        printf("\n");
    }
    return 0;   
}