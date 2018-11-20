/**
 *  URI 1904 - Par ou Ímpar 2.0
 *  Felipe G. Foschiera
 *  Teorema de Lucas e Triângulo de Pascal para saber se o valor de um coeficiente binomial (n, m) é par ou ímpar
 */
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;
const int MAX = 10000000;
typedef long long ll;

ll _sieve_size;
bitset<MAX> bs;
vector<int> primes;

int abs(int x) { return x < 0 ? -x : x;}

void sieve(ll upperbound){
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++){
        if(bs[i]){
            for(ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}

bool ehImpar(int p, int q){
    for(int i = 0; i < 64; i++){
        // Para o número da Combinação(p, q) ser ímpar, 
        // cada i-ésimo bit de q deve ser <= ao i-ésimo bit de p
        // Retorna falso se um bit i de q é > que um bit i de p
        if(((q & (1 << i)) > (p & (1 << i)))) return false;
    }
    return true;

}


int main(){
    sieve(MAX);
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        // n = quantidade de primos no intervalo [p, q] 
        // k = | a - b |
        // Coeficiente (p, q) com repetição:
            // p = n - k + 1
            // q = k
        if(a == b) printf("?\n");
        else {
            if(a > b) swap(a, b);
            auto fs = lower_bound(primes.begin(), primes.end(), a);
            auto sc = lower_bound(primes.begin(), primes.end(), b);
            if(*sc != b) sc--;
            int interval = sc - fs + 1;
            int k = abs(a-b);
            int p = interval + k - 1;
            bool res = ehImpar(p, k);
            printf("%s\n", res ? "Alice" : "Bob");
        }
    }
    return 0;
}