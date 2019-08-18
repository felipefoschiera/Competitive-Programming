#include <bits/stdc++.h>
using namespace std;

const int MAX = 2010;
int n, p, q;

int v[MAX];
int nxtSmall[MAX]; // proximo indice colocando bomba pequena
int nxtBig[MAX]; // proximo indice colocando bomba grande
int pd[MAX][MAX];

int solve(int idx, int big){
    if(idx >= n) return 0;
    if(pd[idx][big] != -1)
        return pd[idx][big];
    int res = solve(nxtSmall[idx], big) + 1; // bomba pequena
    if(big){ // bomba grande (não incrementa a resposta)
        res = min(res, solve(nxtBig[idx], big-1));
    }
    return pd[idx][big] = res;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &p, &q);
        if(n < q) q = n; // não pode ter mais bombas grandes que pessoas
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        sort(v, v+n); // array com as posições das pessoas
        // busca binária para achar o valor w do tamanho da bomba
        int lo = 1, hi = 1e9, best = -1, mid;
        while(lo <= hi){
            mid = (lo+hi)/2;
            // define as posições se a bomba pequena ter tamanho mid
            // preenche os vetores small e big achando a primeira posição no vetor > que a última matada pela bomba
            for(int i = 0; i < n; i++){
                nxtSmall[i] = nxtBig[i] = n; //
                int smallDmg = v[i] + mid - 1;
                int bigDmg = v[i] + 2 * mid - 1;
                for(int j = i+1; j < n; j++){
                    if(v[j] > smallDmg){
                        nxtSmall[i] = j;
                        break;
                    }
                }
                for(int j = i+1; j < n; j++){
                    if(v[j] > bigDmg){
                        nxtBig[i] = j;
                        break;
                    }
                }
            }
            memset(pd, -1, sizeof pd);
            int precisa = solve(0, q); // verifica quantas bombas pequenas precisa, tendo q bombas grandes
            // se precisa menos do que o limite p, é uma solução válida
            if(precisa <= p){
                best = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        printf("%d\n", best);   
    }
    return 0;
}