const int INF = 1e9;
int N, moedas[N];
int dp[MAX]; // inicializar com -1

int troco(int v){
    if(v == 0) return 0; // 0 moedas para produzir 0 centavos
    if(v < 0) return INF; // o caminho utilizado não gera uma solução ótima
    if(dp[v] != -1)
        return dp[v];
    int res = INF;
    for(int i = 0; i < N; i++)
        res = min(res, 1 + troco(v-moedas[i])); // tenta resolver o problema com a moeda
    return dp[v] = res;
}
