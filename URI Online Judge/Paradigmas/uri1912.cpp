// URI 1912 - Ajude Seu Madruga
// Felipe G. Foschiera
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N, A;
    while(scanf("%d %d", &N, &A), N+A){
        int v[N], soma = 0;
        for(int i = 0; i < N; i++) {scanf("%d", v+i); soma += v[i]; }
        if(soma == A) printf(":D\n");
        else if(soma < A) printf("-.-\n");
        else {
            sort(v, v+N);
            double lo = 0.0, hi = 1e4, mid = 0.0, ans = 0.0;
            for(int i = 0; i < 50; i++){
                mid = (lo + hi) / 2.0;
                auto it = lower_bound(v, v+N, mid);
                double areaSum = 0.0;
                for(; it != v+N; ++it){
                    if(*it >= mid) areaSum += (*it - mid);
                    if(areaSum > A) break;
                }
                if(areaSum < A){
                    ans = mid;
                    hi = mid;
                }else{
                    lo = mid;
                }
            }
            printf("%.4lf\n", ans);
        }
    }
    return 0;
}
