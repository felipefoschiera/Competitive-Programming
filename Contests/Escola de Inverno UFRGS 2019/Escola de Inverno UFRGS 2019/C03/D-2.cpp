#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int v[60];

int t, n;
int pd[60][500];

typedef long long ll;

int solve(int idx, int time){
    if(idx == n) return 0;
    if(pd[idx][time] != -1)
        return pd[idx][time];
    int res = 0;
    if(time - v[idx] >= 0)
        res = max(res, v[idx] + solve(idx+1, time - v[idx]));
    res = max(res, solve(idx+1, time));

    return pd[idx][time] = res;
}

int main(){
    while(scanf("%d", &t), t != 0){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        memset(pd, -1, sizeof pd);
        int soma = solve(0, t);
        int h = t;
        for(int i = 0; i < n; i++){
            if(v[i] > h) continue;
            // verifica se pegar o item ainda maximiza a resposta
            if(v[i] + solve(i+1, h - v[i]) == solve(i, h)){
                printf("%d ", v[i]);
                h -= v[i];
            }
        }
        printf("%d\n", soma);
    }
    return 0;
}