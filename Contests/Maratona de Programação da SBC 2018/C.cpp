#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 100055

typedef long long ll;

void compressaoCoordenadas(int *vet, int n){
    int aux[n];
    for(int i = 0; i < n; i++) aux[i] = vet[i];
    sort(aux, aux+n);
    for(int i = 0; i < n; i++) vet[i] = lower_bound(aux, aux+n, vet[i]) - aux + 1;
}

class FenwickTree {
private: vector<int> ft;
public:
    FenwickTree(int n){ ft.assign(n+1, 0); }
    void update(int k, int v) {
        for(; k < (int)ft.size(); k += (k & (-k))) ft[k] += v;
    }
    int rsq(int b){
        int res = 0; 
        for(; b; b -= (b & (-b))) res += ft[b]; 
        return res; 
    }
};

ll intersectionCount(int *l, int *r, int n){
    FenwickTree ft(n);
    ll count = 0;
    vector<pair<int, int> > lines;
    for(int i = 0; i < n; i++) lines.push_back({l[i], r[i]});
    sort(lines.begin(), lines.end());
    for(int i = 0; i < n; i++){
        count += (ll)i - ft.rsq(lines[i].second);
        ft.update(lines[i].second, 1);
    }
    return count;
}

int main(){
    while(scanf("%*d %*d") != EOF){
        ll h, v;
        int left[MAX], right[MAX];
        scanf("%lld %lld", &h, &v);
        for(int i = 0; i < h; i++)
            scanf("%d %d", &left[i], &right[i]);
        ll res = 1 + h + v; // Base de áreas é 1 + quantidade de linhas
        res += h * v; // Toda linha horizontal tem uma intersecção com cada linha vertical
        compressaoCoordenadas(left, h);
        compressaoCoordenadas(right, h);
        res += intersectionCount(left, right, h);
        for(int i = 0; i < v; i++)
            scanf("%d %d", &left[i], &right[i]);
        compressaoCoordenadas(left, v);
        compressaoCoordenadas(right, v);
        res += intersectionCount(left, right, v); 
        printf("%lld\n", res);

    }
    return 0;
}