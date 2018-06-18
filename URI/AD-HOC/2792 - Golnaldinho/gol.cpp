/**
 *  URI 2792 - Golnaldinho
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <string.h>
#define MAX 500001
using namespace std;

int LSOne(int n){
    return n & (-n);
}

int ft[MAX];

int rsq(int a){
    int soma = 0;
    while(a > 0){
        soma += ft[a];
        a -= LSOne(a);
    }
    return soma;
}

void update(int a, int v){
    while(a < MAX){
        ft[a] += v;
        a += LSOne(a);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    memset(ft, 0, sizeof ft);
    int x;
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        printf("%d%s", (x - rsq(x)), (i == n ? "\n" : " "));
        update(x, 1);
    }

    return 0;
}