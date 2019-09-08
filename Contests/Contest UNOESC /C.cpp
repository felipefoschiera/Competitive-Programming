#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

ll lcm(ll a, ll b){
    return (a*b) / __gcd(a, b);
    
}

int main(){
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        ll l = lcm(a, b);
        ll x = (l/a) % MOD, y = (l/b) % MOD;
        cout << x << " " << y << '\n';
    }
    return 0;
}