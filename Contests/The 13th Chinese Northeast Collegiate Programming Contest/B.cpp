#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100010;

int lim[MAX];
ll pd[MAX];

struct doce {
    int val, tipo;
    bool operator < (const doce other) const {
        if(tipo != other.tipo)
            return tipo < other.tipo;
        return val > other.val;
    }
};

doce doces[MAX];

int main(){
    int T;
    scanf("%d",&T);
    int n, m;
    while(T--){
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= m; i++)
            scanf("%d",&lim[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d %d",&doces[i].val, &doces[i].tipo);
        // ordena por tipo depois maior valro
        sort(doces+1, doces+n+1);

        memset(pd, 0, sizeof pd);
        for(int i = 1, j = 0; i <= n; i = j){
            for(j = i; j <= n && doces[i].tipo == doces[j].tipo; j++);
            ll s = 0;
            // testa o intervalo de um mesmo tipo de doces
            for(int k = i; k < j; k++){
                s += doces[k].val;
                // verifica se o tamanho atual do intervalo está no limite
                if(k-i+1 == lim[doces[i].tipo])
                    pd[k-i+1] += s;
                if(k-i+1 > lim[doces[i].tipo])
                    pd[k-i+1] += doces[k].val;
            }
        }
        // pd[i] guarda a maior resposta de tamanho i
        for(int i = 1; i <= n; i++)
            pd[i] += pd[i-1];


        // pd/i > A/B igual a pd * B > A * i
        // busca o maior pd[i]/i e salva em A e B
        ll A = pd[1], B = 1;
        for(int i = 2; i <= n; i++)
            if(pd[i] * B > A * i)
                A = pd[i], B = i;
        ll d = __gcd(A,B);
        printf("%lld/%lld\n",A / d,B / d);
    }
}