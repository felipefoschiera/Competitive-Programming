#include <iostream>
#include <string.h> // memset
#include <queue> // priority queue
#include <vector>
#define MAX 11234
#define INFTO 1123456789
using namespace std;
typedef pair<int, int> ii;

int N, E; // vertices, arestas
int LG[MAX][MAX]; // Lista de adjacência. Lg[u][i] é o iésimo vizinho de u.
int d[MAX]; // Quantidade de vizinhos/arestas saindo de u.
int AG[MAX][MAX]; // Pesos das areastas. AG[u][w] é o peso de u a w.
int dist[MAX]; // Distancias a partir de s até o vértice u.


void dijkstra(int s){
    int u, w, i;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for(u = 1; u <= N; u++){
        dist[u] = INFTO;
    }
    dist[s] = 0;
    pq.push(ii(0, s)); // Par de custo/distancia e vértice.
    while(!pq.empty()){
        u = pq.top().second; pq.pop(); // Seleciona um vértice e o remove da fila.
        for(i = 0; i < d[u]; i++){ // Para cada vizinho de u.
            w = LG[u][i]; // w é o vértice vizinho.
            if(dist[u] + AG[u][w] < dist[w]){
                dist[w] = dist[u] + AG[u][w];
                pq.push(ii(dist[w], w)); // Colocamos o vértice w na fila.
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int i, u, w, peso;
    while(cin >> N >> E){
        for(i = 1; i <= E; i++){
            cin >> u >> w >> peso;
            LG[u][d[u]++] = w;
            LG[w][d[w]++] = u;
            AG[u][w] = AG[w][u] = peso;
        }
        dijkstra(1);
        if(dist[N] != INFTO){
            cout << dist[N] << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}