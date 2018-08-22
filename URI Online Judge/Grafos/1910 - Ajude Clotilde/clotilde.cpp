// URI 1910 - Ajude Clotilde
// Felipe G. Foschiera
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 112345
#define INF ((int)1e9)
using namespace std;
int O, D, K;

vector<int> dist, proibido;

int changeChannel(int canal, int i){
    if(i == 0) return canal+1;
    if(i == 1) return canal-1;
    if(i == 2) return canal << 1;
    if(i == 3) return canal * 3;
    if(i == 4) return canal >> 1;
    return 0;
}

int bfs(){
    dist.assign(MAX, INF);
    queue<int> fila;
    dist[O] = 0;
    fila.push(O);
    while(!fila.empty()){
        int v = fila.front();
        fila.pop();
        if(v == D) return dist[v];
        for(int i = 0; i < 5; i++){
            if(i < 4 || (i == 4 && v % 2 == 0)){
                int novo = changeChannel(v, i);
                if((!proibido[novo]) && novo > 0 && novo <= 100000){
                    if(dist[novo] > dist[v] + 1){
                        dist[novo] = dist[v] + 1;
                        fila.push(novo);
                    }
                }
            }
        }
    }
    return -1;
}


int main(){
    while(scanf("%d %d %d", &O, &D, &K), (O+D+K)){
        proibido.assign(MAX, 0);
        int v;
        for(int i = 0; i < K; i++){
            scanf("%d", &v);
            proibido[v] = 1;
        }
        printf("%d\n", bfs());
    }
    return 0;
}