#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[101010];

int main(){
    int m;
    scanf("%d", &m);
    for(int tc = 1; tc <= m; tc++){
        int n; scanf("%d", &n);
        
        for(int i = 0; i < n; i++){
            scanf("%lld", &v[i]);
        }
        sort(v, v+n);
        int res = 0;
        
        ll curtime = 0;
        for(int i = 0; i < n; i++){
            curtime += v[i];
            ll ddl = 2*v[i];
            if(curtime <= ddl) res++;
            else {
                curtime -= v[i];
            }
        }
        printf("Case #%d: %d\n", tc, res);
    }
    return 0;
}