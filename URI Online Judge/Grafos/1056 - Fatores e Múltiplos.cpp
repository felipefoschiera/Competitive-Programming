#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
const int MAX = 112;

int A[MAX], B[MAX];
bool graph[MAX][MAX];

bool bipartiteMatch(int u, vector<bool> &visited, vector<int> &assign){
    for(int v = 0; v < M; v++){
        if(graph[u][v] && !visited[v]){
            visited[v] = true;
            if(assign[v] < 0 || bipartiteMatch(assign[v], visited, assign)){
                assign[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Encontra o emparelhamento máximo no grafo
int maxMatch(){
    vector<int> assign(M, -1);
    int count = 0;
    for(int u = 0; u < N; u++){
        vector<bool> visited(M, false);
        if(bipartiteMatch(u, visited, assign)) count++;
    }
    return count;
}

// Gera a matriz de adjacências onde graph[i][j] é 1 se j é multiplo de i
void geraGrafo(){
    memset(graph, 0, sizeof graph);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(A[i] == 0){
                // 0 é multiplo de 0
                if(B[j] == 0) graph[i][j] = true;
            }else{
                // quando 0 não é o denominador, verifica-se a divisão
                if(B[j] % A[i] == 0)
                    graph[i][j] = true;
            }
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++){
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        scanf("%d", &M);
        for(int i = 0; i < M; i++)
            scanf("%d", &B[i]);            
        geraGrafo();
        int res = maxMatch();
        printf("Case %d: %d\n", tc, res);
    }


    return 0;
}
