#include <bits/stdc++.h>
using namespace std;
#define MAX 1023456

typedef double ld;

double smartForce(int n){
    if(n == 1)
        return (ld) 0.0;
    return (ld)(n-1) - (((ld)(n-2)) / (ld)3.0);
}

double ans[MAX];

void generate(int LIM){
    ans[1] = 0.0;
    for(int i = 2; i < LIM; i++){
        ans[i] = ans[i-1] + smartForce(i);
        assert(ans[i-1] < ans[i]);
    }
}

int main(){
    int n;
    generate((int)1e6+1);
    while(scanf("%d", &n) != EOF){
        printf("%.10lf\n", ans[n]);
    }
    return 0;
}
