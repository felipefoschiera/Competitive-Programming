#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
typedef long long ll;

ll acum[31630];
int main(){
    int q;
    cin >> q;
    acum[1] = 3;

    for(int j = 2; j < 31630; j++){
        ll k = ((j+1)*(j+1)) - j*j;
        ll z = k*j;
        acum[j] = z + acum[j-1];
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        int raiza = sqrt(a), raizb = sqrt(b);
        ll res = acum[raizb-1] - acum[raiza];
        ll x = ((raiza+1)*(raiza+1)) - a;
        ll y = b - (raizb*raizb) + 1;
        ll k1 = ((x % MOD) * (raiza % MOD)) % MOD;
        ll k2 = ((y % MOD) * (raizb % MOD)) % MOD;

        res = ((res % MOD) + (k1 % MOD)) % MOD;
        res = ((res % MOD) + (k2 % MOD)) % MOD;
        cout << res << '\n';
    }
    return 0;
}   