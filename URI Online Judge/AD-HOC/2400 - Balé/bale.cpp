#include <stdio.h>
#include <algorithm>
#define MAX 112345
using namespace std;

int ft[MAX];

void update(int k, int v){
    while(k < MAX){
        ft[k] += v;
        k += (k & (-k));
    }
}

int rsq(int b){
    int soma = 0;
    while(b > 0){
        soma += ft[b];
        b -= (b & (-b));
    }
    return soma;
}


int main(){
    int N, pares = 0;
    scanf("%d", &N);
    int dancarinas[N];
    for (int i = 0; i < N; i++){
        scanf("%d", dancarinas + i);
        pares += i - rsq(dancarinas[i]);
        update(dancarinas[i], 1);
    }
    printf("%d\n", pares);
    return 0;
}