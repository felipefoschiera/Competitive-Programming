#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    ll u;
    while(scanf("%d %d %lld", &n, &m, &u) != EOF){
        ll A[n];
        for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
        int l, r, p;
        ll v;
        while(m--){
            scanf("%d %d %lld %d", &l, &r, &v, &p);
            int less = 0;
            for(int i = l; i <= r; i++) less += A[i] < v;
            A[p] = u*less / ( r - l + 1);
        }
        for(int i = 1; i <= n; i++) printf("%lld\n", A[i]);
    }

    return 0;
}