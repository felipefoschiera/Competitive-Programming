#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 101010;

bitset<MAXN> bs;
vector<int> primes;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= MAXN; i++){
        if(bs[i]){
            for(ll j = i*i; j <= MAXN; j += i) bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}


class FenwickTree {
private: vector<int> ft;
public:
    FenwickTree(){
        ft.assign(MAXN, 0);
    }
    void update(int k, int v){
        for(; k <= MAXN; k += (k & -k))
            ft[k] += v;
    }
    int rsq(int b){
        int sum = 0;
        for(; b; b -= (b & -b))
            sum += ft[b];
        return sum;
    }
    int rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0 : rsq(a-1));
    }

};

typedef pair<pair<int, int>, int> query;

int main(){
    sieve();
    int Q;
    scanf("%d", &Q);
    vector<query> queries(Q);
    for(int i = 0; i < Q; i++){
        scanf("%d %d", &queries[i].first.second, &queries[i].first.first);
        queries[i].second = i;
    }
    // Ordenada as queries por K
    sort(queries.rbegin(), queries.rend());

    FenwickTree ft;
    for(int i = 1; i < MAXN; i++)
        ft.update(i, 1);
    
    int PF = primes.size() - 1;
    // Para cada query a partir da com maior K, vai testando os primos maiores que K
    // E desativando-os no vetor.
    // A quantidade de números de [2, N] é calculada com a rsq, e conta quantos números
    // de [2, N] não tem como fator primo os valores > K, que foram desativados.
    vector<int> res(Q);
    for(int i = 0; i < Q; i++){
        int k = queries[i].first.first;
        int n = queries[i].first.second;
        while(PF >= 0 && primes[PF] > k){
            for(int j = primes[PF]; j < MAXN; j += primes[PF]){
                if(ft.rsq(j, j) != 0)
                    ft.update(j, -1);
            }
            PF--;
        }
        res[queries[i].second] = ft.rsq(2, n);
    }
    for(int i = 0; i < Q; i++){
        printf("%d\n", res[i]);
    }
    return 0;
}