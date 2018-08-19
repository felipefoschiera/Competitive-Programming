#include <cstdio>
#define MAX 1123
using namespace std;

int N;
int color[MAX], mat[MAX][MAX];

/**
 *  A função testaBipartido busca verificar se um vértice v que não pode estar junto a um vértice u tem uma cor diferente de u.
 *  Quando v já tem cor definida, retorna verdadeiro se for igual a cor pesquisada na dfs, que é a contrária ao vértice u,
 *  que não tem um caminho a v.
 *  Quando não tem cor definida, define a cor da dfs, que com certeza é
 *  diferente da do vértice u que chamou v por não ter um caminho a v.
 * 
 */
bool testaBipartido(int s, int cor){
    if(color[s] != -1) return color[s] == cor; 
    color[s] = cor;
    for(int v = 0; v < N; v++){
        if(!mat[s][v])
            if(!testaBipartido(v, !cor)) return false;
    }
    return true;
}

/**
 *  A função ehBipartido verifica se é possível fazer a coloração do grafo em duas cores/dois conjuntos.
 *  Quando algum testaBipartido retorna falso, a função ehBipartido também vai, por não ser possível completar a coloração.
 */
bool ehBipartido() {
    for(int i = 0; i < N; i++) color[i] = -1;
    for(int i = 0; i < N; i++)
        if(color[i] == -1)
            if(!testaBipartido(i, 1)) return false;
    return true;
}

int main(){
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                scanf("%d", &mat[i][j]);
            }
        printf("%s\n", ehBipartido() ? "Bazinga!" : "Fail!");
    }

    return 0;
}