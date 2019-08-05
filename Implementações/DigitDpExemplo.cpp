// Faz a soma de todos os dígitos entre os números [A, B]

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

// 20 -> maximo de 18 digitos para um número de 64 bits
// 180 -> maior soma dos digitos 9*18 = 162 = ~ 200
// 2 -> tight 1 ou 0
ll dp[20][180][2];

void getDigits(ll x, vector<int> &digit){
    while(x){
        digit.push_back(x%10);
        x /= 10;
    }
}

ll digitSum(int idx, int sum, int tight, vector<int> &digit){
    if(idx == -1) return sum % MOD;
    if(dp[idx][sum][tight] != -1 && tight != 1)
        return dp[idx][sum][tight];
    ll ret = 0;
    int k = (tight) ? digit[idx] : 9;
    for(int i = 0; i <= k; i++){
        int newTight = (!tight) ? 0 : (digit[idx] == i);
        // ret += digitSum(idx-1, sum+i, newTight, digit);
        ret = (ret + digitSum(idx-1, sum+i, newTight, digit)) % MOD;
    }
    if(!tight)
        dp[idx][sum][tight] = ret;
    return ret;
}

ll rangeDigitSum(ll a, ll b){
    memset(dp, -1, sizeof dp);
    vector<int> digitA;
    getDigits(a-1, digitA);
    // finding sum of digits from 1 to a-1 which is passed as digitA
    ll ans1 = digitSum(digitA.size()-1, 0, 1, digitA);
    vector<int> digitB;
    getDigits(b, digitB);
    ll ans2 = digitSum(digitB.size()-1, 0, 1, digitB);
    return ans2 - ans1;
}

int main(){
    ll A, B;
    while(scanf("%lld %lld", &A, &B) != EOF){
        printf("%lld\n", rangeDigitSum(A, B));
    }
    return 0;
}