#include <stdio.h>
#include <algorithm>
#define INF ((int)1e9)
using namespace std;

int main(){
    int N, tc = 1;
    while(scanf("%d", &N), N){
        int v[N];
        for(int i = 0; i < N; i++) scanf("%d", v+i);
        sort(v, v+N);
        int m, sum;

        printf("Case %d:\n", tc++);
        scanf("%d", &m);
        while(m--){
            scanf("%d", &sum);
            int diff = INF, best_sum;
            for(int i = 0; i < N; i++)
                for(int j = i+1; j < N; j++){
                    int soma = v[i] + v[j];
                    if(abs(soma - sum) < diff){
                        diff = abs(soma - sum);
                        best_sum = soma;
                    }
                }
            printf("Closest sum to %d is %d.\n", sum, best_sum);
        }
    }
    return 0;
}