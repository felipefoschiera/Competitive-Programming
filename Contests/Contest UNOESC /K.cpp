#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

ll power(ll a, ll b){
    if(b == 0) return 1LL;
    if(b&1) return (a * (power(a, b-1))) % MOD;
    ll c = power(a, b/2);
    return (c*c) % MOD;
}

int main(){
    int q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll p = (((n-1) % MOD) * ((n+2LL) % MOD)) % MOD;
        ll k = power(2LL, MOD-2);
        p = ((p % MOD) * (k % MOD)) % MOD;
        p = ((p % MOD) + (2LL % MOD)) % MOD;
        cout << p << '\n';
    }
    return 0;
}