#include <cstdio>
#include <cstring>
#define INF ((int)1e9)
#define MAX 18

inline int min(int a, int b) { return a < b ? a : b; }
int n, dp[1 << MAX], cost[MAX][MAX];

/**
 *  Com uma restrição pequena, pode-se resolver com programação dinâmica e máscara de bits,
 *  testando todas as possibilidades de ordem de contratação dos jogadores.
 *  A função solve inicia com a bitmask em 0 e é completa quando todos os N bits são 1.
 *  Para N = 1, (2^N)-1 = 7 que em binário é 111.
 *  Com a bitmask vazia, iniciamos no jogador 0 e testamos, para cada outro que ainda não foi
 *  contradado nessa bitmask, se sua contratação (e ativação do bit) tem um custo menor na resposta final.
 *  Continuamos recursivamente, resolvendo completando a bitmask bit por bit e incrementando o custo
 *  naquela ordem.
 * 
 *  bitmask & (1 << i) verifica se o i-ésimo bit da direita para esquerda está ativo
 *  bitmask | (1 << i) ativa i-ésimo bit.
 *  dp[(1 << n)-1] é igual a 0 pois com a bitmask (2^n)-1 todos os bits estão ativos e não
 *  há mais contratações para serem feitas.
 * 
 */

int target;

int solve(int bitmask, int done){
    if(dp[bitmask] != -1) return dp[bitmask];
    if(bitmask == target) return 0;
    int best = INF;
    for(int i = 0; i < n; i++)
        if(!(bitmask & (1 << i)))
            best = min(best, solve(bitmask | (1<<i), done+1) + cost[done][i]);
    return dp[bitmask] = best;
}

int main(){
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &cost[i][j]);
        memset(dp, -1, sizeof dp);
        target = (1 << n) - 1;
        printf("%d\n", solve(0, 0));
    }
    return 0;
}