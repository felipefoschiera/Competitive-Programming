#include <stdio.h>
#define MAX 112345
using namespace std;

int points[MAX], pai[MAX];

int findSet(int x){
    return pai[x] == x ? x : pai[x] = findSet(pai[x]);
}

void unionSet(int a, int b){
    points[findSet(a)] += points[findSet(b)];
    pai[findSet(b)] = findSet(a);
}

int main(){
    int N, M;
    while(scanf("%d %d", &N, &M) && (N+M)){
        for(int i = 0; i < N; i++){
            scanf("%d", points+i);
            pai[i] = i;
        }
        int rafael = 0, wins = 0;
        int Q, a, b;
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &Q, &a, &b);
            a--, b--;
            if(Q == 1){
                unionSet(a, b);
            }else{
                if(findSet(a) == findSet(b)) continue;
                if(findSet(a) == findSet(rafael)){
                    wins += points[findSet(a)] > points[findSet(b)];
                }else if(findSet(b) == findSet(rafael)){
                    wins += points[findSet(b)] > points[findSet(a)];
                }
            }
        }
        printf("%d\n", wins);
    }
}