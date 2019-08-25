#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000100;
bitset<MAX> bs;
vector<ll> primes;
void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i < MAX; i++){
        if(bs[i]){
            for(ll j = i*i; j < MAX; j += i) bs[j] = 0;
            primes.push_back(i);
        }
    }
}

bool ehDesp(ll N){
    int cnt = 0;
    ll PF_idx = 0, PF = primes[PF_idx];
    while(PF * PF <= N){
        if(N % PF == 0){
            cnt++;
            int c = 0;
            while(N % PF == 0){
                N /= PF;
                c++;
            }
            if(c > 1) return false;
        }
        PF = primes[++PF_idx];
    }
    if(N != 1) cnt++;
    return cnt >= 2;
}

int main(){
    sieve();
    ll N;
    cin >> N;
    ll res = 0;
    for(ll i = 1; i*i <= N; i++){
        if(N % i == 0){
            if(ehDesp(i)) res++;
            if(i != N/i && ehDesp(N/i)) res++;
        }
    }
    cout << res << '\n';
    return 0;
}