#include <cstdio>
#include <bitset>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX = 2000100;

vector<ll> primes;
bitset<MAX> bs;

void sieve(){
    bs.set(0);
    bs.set(1);
    for(ll i = 2; i < 1500; i++)
        if(!bs[i]) {
            for(ll j = i*i; j < MAX; j += i) bs.set(j);
            primes.push_back(i);
    }
}

int numDiv(ll N){
    int ans = 1, PF_idx = 0;
    ll PF = primes[PF_idx];
    while(PF*PF <= N){
        int power = 0;
        while(N % PF == 0) { N /= PF; power++; }
        ans *= (power + 1);
        PF = primes[++PF_idx];
    }
    if(N != 1) ans += 2;
    return ans;
}

int hiperPrimo[MAX];

bool ehQuadradoPerfeito(int n){
    int s = sqrt(n);
    return n == s*s;
}

int main(){
    int N;
    sieve();
    hiperPrimo[2] = 1;
    for(int i = 3; i < MAX; i++){
        // O único número par primo é o 2 (numero de divisores de um i primo),
        // e somente números quadrados perfeitos tem um número impar de divisores
        // então só testamos a primalidade dos divisores de um número quadrado perfeito.
        if(!bs[i] || (ehQuadradoPerfeito(i) && !bs[numDiv(i)])){
            hiperPrimo[i] = 1;
        }
        hiperPrimo[i] += hiperPrimo[i-1];
    }
    while(scanf("%d", &N) != EOF){
        printf("%d\n", hiperPrimo[N]);
    }
    return 0;
}