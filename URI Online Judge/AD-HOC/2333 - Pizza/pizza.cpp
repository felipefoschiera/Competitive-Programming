#include <cstdio>

const int MAX = 101010;

int n, v[MAX];

inline int max(int a, int b) { return a > b ? a : b; }

int kadane(){
    int sum = 0, best = 0;
    for(int i = 0; i < n; i++){
        sum = max(sum+v[i], v[i]);
        best = max(sum, best);
    }
    return best;
}

int maxCircularSum(){
    int max_kadane = kadane();
    int max_wrap = 0;
    for(int i = 0; i < n; i++){
        max_wrap += v[i];
        v[i] = -v[i];
    }
    max_wrap += kadane();
    return max(max_wrap, max_kadane);
}

int main(){
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
            printf("%d\n", maxCircularSum());
    }
    return 0;
}