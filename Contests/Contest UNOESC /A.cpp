#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll n){
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;
    for(ll i = 3; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int m;
    cin >> m;
    while(m--){
        ll n, a, b;
        cin >> n >> a >> b;
        ll lva = log2(a+1);
        if(a == 0) lva = 0;
        ll lvb = log2(b+1);
        if(b == 0) lvb = 0;
        if(lva < lvb){
            swap(lva, lvb);
            swap(a, b);
        }
        while(lva != lvb){
            a--; a /= 2; lva--;
        }

        while(a != b){
            a--; a /= 2; b--; b /= 2;
        }
        cout << a << ' ' << isPrime(a) << '\n';
    }
    return 0;
}