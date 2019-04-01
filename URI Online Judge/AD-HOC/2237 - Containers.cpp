#include <cstdio>
#include <queue>
#include <map>
using namespace std;

struct container {
    int mat[2][4];

    bool operator < (const container &other) const{
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 4; j++){
                if(mat[i][j] != other.mat[i][j])
                    return mat[i][j] < other.mat[i][j];
            }
        }
        return false;
    }

    bool operator == (const container &other) const {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 4; j++){
                if(mat[i][j] != other.mat[i][j]) return false;
            }
        return true;
    }

};


typedef pair<int, container> cont;

int dijkstra(container &inicio, container &fim){
    map<container, bool> visited;
    map<container, int> dist;
    dist[inicio] = 0;
    priority_queue<cont, vector<cont>, greater<cont>> pq;
    // pq.insert({0, inicio});
    pq.push({0, inicio});
    while(!pq.empty()){
        // int d = pq.begin()->first;
        // container u = pq.begin()->second;
        // pq.erase(pq.begin());
        int d = pq.top().first;
        container u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;

        if(u == fim){ return d; }
        // faz as trocas nas colunas
        for(int i = 0; i < 4; i++){
            container aux = u;
            swap(aux.mat[0][i], aux.mat[1][i]);
            int custo = d + aux.mat[0][i] + aux.mat[1][i];
            if(!dist.count(aux) || dist[aux] > custo){
                // pq.erase({dist[aux], aux});
                dist[aux] = custo;
                pq.push({custo, aux});
                // pq.insert({custo, aux});
            }
        }
        // troca nas linhas
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                container aux = u;
                swap(aux.mat[i][j], aux.mat[i][j+1]);
                int custo = d + aux.mat[i][j] + aux.mat[i][j+1];
                if(!dist.count(aux) || dist[aux] > custo){
                    // pq.erase({dist[aux], aux});            
                    dist[aux] = custo;
                    pq.push({custo, aux});
                    // pq.insert({custo, aux});
                }
            }
        }
    }
}
int main(){
    container inicio, fim;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 4; j++)
            scanf("%d", &inicio.mat[i][j]);
    
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 4; j++)
            scanf("%d", &fim.mat[i][j]);
    printf("%d\n", dijkstra(inicio, fim));
    return 0;
}
