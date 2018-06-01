/**
 *  URI 1835 - Promessa de Campanha
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> pai;

int findSet(int x){
    return (pai[x] == x) ? x : pai[x] = findSet(pai[x]);
}

bool isSameSet(int x, int y){
    return findSet(x) == findSet(y);
}

void unionSet(int x, int y){
    pai[findSet(x)] = findSet(y);
}


int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        int N, M;
        scanf("%d %d", &N, &M);        
        pai.assign(N, 0);
        for(int i = 0; i < N; i++) pai[i] = i;
        int a, b;
        for(int i = 0; i < M; i++){
            scanf("%d %d", &a, &b);
            a--, b--;            
            if(!isSameSet(a, b)){
                unionSet(a, b);
                N--;
            }
        }
        printf("Caso #%d: ", t);
        if(N == 1){
            printf("a promessa foi cumprida\n");
        }else{
            printf("ainda falta(m) %d estrada(s)\n", N-1);
        }
    }
    return 0;
}