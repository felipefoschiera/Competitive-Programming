#include <stdio.h>
#include <utility>
using namespace std;
int z, i, m;

int f(int x){
    return (z * x + i) % m;
}

int floydCycleFinding(int x0){
    int tortoise = f(x0), hare = f(f(x0));
    while(tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
    int mu = 0; hare = x0;
    while(tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++; }
    int lambda = 1; hare = f(tortoise);
    while(tortoise != hare) { hare = f(hare); lambda++; }
    return lambda;
}

int main(){
    int tc = 1;
    int l;
    while(scanf("%d %d %d %d", &z, &i, &m, &l), z+i+m+l){

        int res = floydCycleFinding(l);
        printf("Case %d: %d\n", tc++, res);
    }
    
    return 0;
}