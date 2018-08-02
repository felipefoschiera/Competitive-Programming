/**
 *  Seletiva UFFS 2018 - URI Online Judge
 *  Felipe G. Foschiera
 */
#include <iostream>
#include <string.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll fat(int n){
    if(n == 0) return 1;
    return (n * fat(n-1)) % MOD;
}

ll power(ll a, ll b){
    if(b == 0) return 1;
    if(b&1) return (a * power(a, b-1)) % MOD;
    ll calc = power(a, b >> 1);
    return (calc * calc) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int sz = s.length();
    ll ans = fat(sz);
    int freq[26];
    memset(freq, 0, sizeof freq);
    for(int i = 0; i < sz; i++) freq[s[i] - 'a']++;
    ll denom = 1;
    for(int i = 0; i < 26; i++){
        denom = ((denom % MOD) * (fat(freq[i]) % MOD)) % MOD;
    }
    ans = (ans * power(denom, MOD-2)) % MOD;
    cout << ans << endl;
    
    return 0;
}