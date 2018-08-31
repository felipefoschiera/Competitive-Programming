#include <stdio.h> // Entrada e saida padrão
#include <cmath> // Biblioteca cmath, para utilizar a funcao abs() que mostra o valor absoluto da diferenca entre dois numeros
#include <queue> // Biblioteca queue, para vector e fila de prioridade
#define INFINITO 1e9 // Infinito = 1e9, grande o suficiente para calcularmos o menor caminho
using namespace std;
typedef pair<int, int> aresta; // par de inteiros - aresta(vai conter um vértice o custo até ele)
typedef vector<aresta> vetor_arestas;    // Vector de pares/arestas - vetor_arestas

vector<vetor_arestas> adj;   // Lista de adjacência, o índice i de adj contem uma própria lista com pares(vértice ligado, custo)
vector<int> dist; // Armazena as distâncias calculadas a partir do vértice inicial

void dijkstra(int s, int N) {                      // Calcula as distâncias a partir de s, para um grafo de N vertices
    dist.assign(N, INFINITO);                      // Inicia a lista de distâncias com INFINITO (1 elevado na 9), pois a distância ainda não foi calculada
    dist[s] = 0;                                   // A distância do vértice inicial a ele mesmo é zero
    priority_queue<aresta, vector<aresta>, greater<aresta>> fila; // Fila de prioridade que remove o menor elemento(menor custo, e armazena pares de vértices)
    fila.push(aresta(0, s));                              // Iniciamos a fila com um par (0, s) - custo 0 para chegar ao vértice inicial s (ele mesmo)
    while (!fila.empty()) { // Enquanto houverem elementos na fila
        int u = fila.top().second; // Armazenamos o vértice mais próximo(topo da fila de prioridade) na variável u.
        // Second pois o primeiro elemento do par contém o custo até lá, e o segundo o número do vértice.
        fila.pop(); // E o removemos da fila.
        for (auto vizinho : adj[u]) { // Para cada vizinho de u, ou seja, para cada elemento na lista de adjacencia de u
            int v = vizinho.first;   // v é o primeiro elemento do par, que é o vértice
            int w = vizinho.second;  // w é o segundo elemento do par, que é o custo para se chegar até lá a partir de u
            if (dist[v] > dist[u] + w) { // Se a distância atual calculada até v é maior que a distância até u e o peso da aresta de u a w
                dist[v] = dist[u] + w;   // Significa que achamos um caminho mais próximo, e o substituímos na distância até vs
                fila.push(aresta(dist[v], v));  // E colocamos o vértice v com o custo até chegar nele na fila de prioridade, para ser visitado.
            }
        }
    }
}

int main() {
    int N, M, C, K;
    // N = numero de vértices/cidades, M = numero de arestas/estradas, C = numero de cidades na rota(de 0 a C-1), e K = cidade inicial    
    while (scanf("%d %d %d %d", &N, &M, &C, &K)){
        if(N == 0 && M == 0 && C == 0 && K == 0) break; // Enquanto forem lidos valores para N, M, C, e K e não forem todos zeros

        adj.assign(N, vetor_arestas()); // Definimos que para cada um dos N vértices, há um vetor de pares de inteiros vazio em sua lista de adjacências
        int u, v, w;
        for (int i = 0; i < M; i++) { // Lendo as M arestas
            scanf("%d %d %d", &u, &v, &w);
            // Se ambas os vértices estão fora da rota(ou seja, são maiores que C-1)
            // Ou se ambos estão dentro da rota e ligados consecutivamente
            // Adicionamos uma aresta bidirecional entre eles.
            if ((u >= C && v >= C) || (u < C && v < C && abs(u - v) == 1)) {
                adj[u].push_back(aresta(v, w));
                adj[v].push_back(aresta(u, w));
            }
            // Se u está fora da rota e v está dentro, adicionamos a aresta direcionada
            // de u para v (para entrar na rota), mas não o contrário, pois quando entramos na rota
            // não podemos mais sair dela.
            if (u >= C && v < C) {
                adj[u].push_back(aresta(v, w));
            }
            // Mesma coisa para se v estiver fora da rota e u dentro.
            if (v >= C && u < C) {
                adj[v].push_back(aresta(u, w));
            }
        }
        // Utilizamos o Dijkstra para calcular as distâncias dos N vértices a partir do vértice inicial K.
        // E como definimos a direção de nossas arestas seguindo as restrições do problema, não precisamos
        // modificar a função Dijkstra internamente.
        dijkstra(K, N);
        // Exibimos a distância até o fim da rota, que é C-1 para uma rota de C cidades
        // numeradas de 0 a C-1.
        printf("%d\n", dist[C - 1]);
    }
    return 0;
}