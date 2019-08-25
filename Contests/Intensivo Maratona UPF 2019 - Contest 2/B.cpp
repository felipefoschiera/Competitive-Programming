#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXP = 100000;
bitset<MAXP> bs;
vector<int> primes;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i < MAXP; i++){
        if(bs[i]){
            for(ll j = i*i; j < MAXP; j += i) bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}

ll eulerPhi(ll N){
    ll i = 0, p = primes[i], ans = N;
    while(p * p <= N){
        if(N % p == 0) ans -= ans / p;
        while(N % p == 0) N /= p;
        p = primes[++i];
    }
    if(N != 1) ans -= ans / N;
    return ans;
}

int main(){
    sieve();
    ll n;
    while(cin >> n){
        ll res = eulerPhi(n) / 2;
        cout << res << '\n';
    }
    return 0;
}