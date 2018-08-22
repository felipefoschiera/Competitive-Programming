#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

class FenwickTree {
private: vector<int> ft;
public:
    FenwickTree(int n) { ft.assign(n+1, 0); }
    ll rsq(int b){
        ll sum = 0;
        for(; b; b -= (b & (-b))) sum += ft[b];
        return sum;
    }
    ll rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0 : rsq(a-1)); 
    }
    void update(int k, int v){
        for(; k < (int)ft.size(); k += (k & (-k))) ft[k] += v; 
    }
};

int main(){
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF){
        FenwickTree ft(N+1);
        int op, x, a, b, c, d;
		ll y;
        while(M--){
            scanf("%d", &op);
            if(op == 1){
                scanf("%d %lld", &x, &y);
                ft.update(x, y);
            }else if(op == 2){
                scanf("%d %d %d %d", &a, &b, &c, &d);
				ll ans;
				if(c > b || a > d) ans = ft.rsq(a, b) + ft.rsq(c, d);
				else ans = ft.rsq(min(a, c), max(b, d));
                printf("%lld\n", ans);
            }
			// 1 2 3 4
			// 3 4 1 2

        }
    }
    return 0;
}