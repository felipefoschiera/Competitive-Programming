// Felipe G. Foschiera
// URI 2539 - High Five
#include <stdio.h>
#include <bits/stdc++.h>
#define MAX 1123450
using namespace std;
typedef long long ll;

int LSOne(int S){
    return (S & (-S));
}

ll bit[MAX];

void update(int i, ll val){
    while(i < MAX){
        bit[i] += val;
        i += LSOne(i);
    }
}

ll rsq(ll i){
    ll soma = 0;
    while(i > 0){
        soma += bit[i];
        i -= LSOne(i);
    }
    return soma;
}

ll rsq(ll a, ll b){
    if(a == 1){
        return rsq(b);
    }else{
        return rsq(b) - rsq(a-1);
    }
}

int main() {
    int N;
    while(scanf("%d", &N) != EOF){
        memset(bit, 0, MAX);
        int pos, v[MAX];
        ll soma = 0;
        for(ll i = 1; i <= N; i++){
            scanf("%d", v+i);
        }
        for(ll i = N; i >= 1; i--){
            update(v[i], 1);
            soma += rsq(v[i] + 1, N);
        }
        printf("%lld\n", soma);

    }

}   