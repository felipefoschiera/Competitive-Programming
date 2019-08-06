#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int v[60];

int t, n;

int pd[60][500];

typedef long long ll;

int melhor, diff;
ll bitmaskres;

int solve(int idx, int time, ll bitmask){
    if(melhor != -1 && bitmaskres == -1 && time == diff){
        bitmaskres = bitmask;
    }
    if(idx == n) return 0;
    if(pd[idx][time] != -1)
        return pd[idx][time];
    int res = 0;
    if(time - v[idx] >= 0)
        res = max(res, v[idx] + solve(idx+1, time - v[idx], bitmask | (1LL << idx)));
    res = max(res, solve(idx+1, time, bitmask));

    return pd[idx][time] = res;
}


int main(){
    while(scanf("%d", &t), t != 0){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        melhor = -1;
        memset(pd, -1, sizeof pd);
        int soma = solve(0, t, 0LL);
        melhor = soma;
        bitmaskres = -1;
        diff = abs(t - melhor);
        memset(pd, -1, sizeof pd);
        solve(0, t, 0LL);
        for(int i = 0; i < n; i++){
            if(bitmaskres & (1LL << i))
                printf("%d ", v[i]);
        }
        printf("%d\n", soma);
    }
    return 0;
}