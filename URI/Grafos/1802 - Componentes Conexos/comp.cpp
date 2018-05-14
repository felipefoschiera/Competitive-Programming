/**
 *  URI 1802 - Componentes Conexos
 *  Union-Find
 *  Felipe G. Foschiera
 * 
 */
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;


int pai[27];

int findSet(int x){
    return (pai[x] == x) ? x : pai[x] = findSet(pai[x]);
}

void unionSet(int a, int b){
    if(findSet(a) > findSet(b)){ // A menor letra é pai da maior, para ficar em ordem;   
        pai[findSet(a)] = findSet(b);
    }else{
        pai[findSet(b)] = findSet(a);
    }
}

int main(){
    int T;
    scanf("%d ", &T);
    for(int t = 1; t <= T; t++){
        int V, A;
        scanf("%d %d ", &V, &A);
        for(int i = 0; i < V; i++){
            pai[i] = i;
        }
        char a, b;
        for(int i = 0; i < A; i++){
            scanf("%c %c ", &a, &b);
            unionSet(a - 'a', b - 'a');
        }
        map<int, vector<int>> connected;
        for(int i = 0; i < V; i++){
            connected[findSet(i)].push_back(i);
        }
        printf("Case #%d:\n", t);        
        for(auto c : connected){
            for(auto i : c.second){
                printf("%c,", 'a'+i);
            }
            printf("\n");
        }
        printf("%ld connected components\n\n", connected.size());
    }
    return 0;
}