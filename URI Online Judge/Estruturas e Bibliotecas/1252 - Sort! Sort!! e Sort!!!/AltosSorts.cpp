// URI 1252 - Sort! Sort!! e Sort!!!
// Felipe G. Foschiera
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

bool cmp(int a, int b){
    int modA = a % M, modB = b % M;
    if(modA != modB) return modA < modB;
    else {
        if((!(a&1) && !(b&1)))
            return a < b;
        if(a&1 && b&1)
            return a > b;
            return a&1 && !(b&1);
        }
    return 0;
}


int main(){
    while(scanf("%d %d", &N, &M)){
        if(N == 0 && M == 0){
            printf("0 0\n");
            break;
        }
        int v[N];
        for(int i = 0; i < N; i++) scanf("%d", v+i);
        sort(v, v+N, cmp);
        printf("%d %d\n", N, M);
        for(int i = 0; i < N; i++) printf("%d\n", v[i]);
    }
    return 0;
}