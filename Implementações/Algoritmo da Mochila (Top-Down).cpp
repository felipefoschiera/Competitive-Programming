
const int MAXN = 60;
const int MAXW = 110;

int pd[MAXN][MAXW]; // inicializar com -1

int valores[MAXN], pesos[MAXN];
int N;

int mochila(int n, int W){ 
    if(n == N || W == 0) return 0;
    if(pd[n][W] != -1)
        return pd[n][W];
    int res = 0;
    if(pesos[n] > W) res = mochila(n+1, W); 
    else {
        res = max(mochila(n+1, W), valores[n] + mochila(n+1, W-pesos[n]));
    }
    return pd[n][W] = res;
}