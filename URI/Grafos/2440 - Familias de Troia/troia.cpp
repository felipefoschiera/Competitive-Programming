/**
 *  URI 2440 - Famílias de Troia
 *  OBI 2013/Nível 2/ Fase 2
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

vector<int> pai;

int findSet(int x){
    return (pai[x] == x) ? x : pai[x] = findSet(pai[x]);
}

void unionSet(int x, int y){
    pai[findSet(x)] = findSet(y);
}


int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int a, b;
    pai.assign(N, 0);
    for(int i = 0; i < N; i++) pai[i] = i;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        a--, b--;
        unionSet(a, b);
    }
    map<int, vector<int>> fam;
    for(int i = 0; i < N; i++){
        fam[findSet(i)].push_back(i);
    }
    printf("%ld\n", fam.size());

    return 0;
}