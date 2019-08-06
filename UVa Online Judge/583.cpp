#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vi primes;
bitset<100100> bs;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= 100000; i++){
        if(bs[i]){
            for(ll j = i*i; j <= 100000; j += i) bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}

vi primeFactors(ll N){
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while(PF * PF <= N){
        while(N % PF == 0) { N /= PF; factors.push_back(PF); }
        PF = primes[++PF_idx];
    }
    if(N != 1) factors.push_back(N);
    return factors;
}

int main(){
    ll n;
    sieve();
    while(cin >> n, n){
        vi factors = primeFactors(abs(n));
        cout << n << " = ";
        if(n < 0) cout << "-1 x ";
        for(int i = 0; i < factors.size(); i++){
            cout << factors[i] << (i == factors.size()-1 ? "\n" : " x ");
        }
    }
    return 0;
}