/**
 *  URI 2089 - Lanchonete
 *  Felipe G. Foschiera
 *  Deu 1.296 segundos mas passou kkkkkkjjjkkk
 */
#include <stdio.h>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int> moedas, int soma){
    vector<bool> possible(soma+1, false);
    possible[0] = true;
    for(auto c : moedas){
        for(int i = soma-c; i >= 0; i--){
            if(possible[i]) possible[i+c] = true;
        }
    }
    return possible[soma];
}

int main(){
    int V, N;
    while(scanf("%d %d", &V, &N) && (V+N)){
        vector<int> moedas;
        int s;
        for(int i = 0; i < N; i++){
            scanf("%d", &s);
            moedas.push_back(s);
        }
        printf(isSubsetSum(moedas, V) ? "sim\n" : "nao\n");
    }   

    return 0;
}