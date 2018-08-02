#include <bits/stdc++.h>
using namespace std;

int custoSort(int ordens[], int n, int custos[]){
    if(n <= 1){
        return 0;
    }
    int custosOriginais[n+1];
    for(int i = 0; i < n; i++){
        int d = ordens[i];
        custosOriginais[d] = custos[i];
    }
    
    int custo = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if (ordens[j] > ordens[j+1]){
                custo += custosOriginais[ordens[j]];
                custo += custosOriginais[ordens[j+1]];
                int temp = ordens[j];
                ordens[j] = ordens[j+1];
                ordens[j+1] = temp;
            }
        }

    }
    return custo;
}

int main() {

    int N;
    while(scanf("%d", &N) != EOF){
        int ordens[N];
        int custos[N];
        for(int i = 0; i < N; i++){
            scanf("%d", ordens+i);
        }
        for(int i = 0; i < N; i++){
            scanf("%d", custos+i);
        }
        printf("%d\n", custoSort(ordens, N, custos));


    }


    return 0;
}