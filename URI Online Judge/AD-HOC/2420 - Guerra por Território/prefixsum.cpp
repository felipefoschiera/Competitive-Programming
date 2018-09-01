#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int v[N], pre[N];
        for(int i = 0; i < N; i++)
            scanf("%d", &v[i]);
        pre[0] = v[0];
        for(int i = 1; i < N; i++) pre[i] = v[i] + pre[i-1];

        int secao;
        for(int i; i < N; i++){
            int fs = pre[i], sc = pre[N-1] - pre[i];
            if(fs == sc) { secao = i; break; }
        }
        printf("%d\n", secao+1);
    }
    return 0;
}