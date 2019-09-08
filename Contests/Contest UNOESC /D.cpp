#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void getDigits(ll x, vector<int> &digit){
    while(x){
        digit.push_back(x%10);
        x /= 10;
    }
    reverse(digit.begin(),digit.end());
}
 

const ll MOD = 1000000007;
int k;
 
ll dp[17][1<<5][1<<5][2][2];
 
ll digitCount(int idx, ll par, ll impar, int tight, bool is_zero, vector<int> &digit){
    if(idx == digit.size()){
        int p = __builtin_popcountll(par);
        int q = __builtin_popcountll(impar);
        if(p >= k && q < k) return 1LL;
        if(q >= k && p < k) return 1LL;
        return 0LL;
    }
    if(dp[idx][par][impar][tight][is_zero] != -1)
        return dp[idx][par][impar][tight][is_zero];
    ll ret = 0;
    int k = (tight) ? digit[idx] : 9;
    for(int i = 0; i <= k; i++){
        int newTight = (digit[idx] == i) ? tight : 0;
        int newZero = (is_zero||(i!=0));
        ll par1 = par;
        ll impar1 = impar;
        if(newZero)
            if(i % 2 == 0)
                par1 |= 1 << (i/2);
            else
                impar1 |= 1 << (i/2);
        ret = ((ret % MOD) + (digitCount(idx+1, par1, impar1, newTight, newZero, digit) % MOD)) % MOD;
    }
    return dp[idx][par][impar][tight][is_zero] = ret;
}
 
 
ll rangeDigitCount(ll a, ll b){
    memset(dp, -1LL, sizeof dp);
    vector<int> digitA;
    getDigits(a-1, digitA);
    ll ans1 = digitCount(0, 0, 0, 1, 0, digitA);
    vector<int> digitB;
     memset(dp, -1LL, sizeof dp);
    getDigits(b, digitB);
    ll ans2 = digitCount(0, 0, 0, 1, 0, digitB);
    return ((ans2 - ans1 + MOD)) % MOD;
}
 
int main(){
    ll a, b;
    while(cin >> a >> b >> k){
        ll res = rangeDigitCount(a, b);
        cout << res << '\n';
    }
    return 0;
}