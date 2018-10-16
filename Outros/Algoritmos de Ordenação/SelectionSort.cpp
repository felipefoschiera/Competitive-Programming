#include "funcoes.cpp"

void selectionsort(int vet[], int n){
    for(int i = 0; i < n-1; i++){
        int k = i;
        for(int j = i+1; j < n; j++){
            if(vet[j] < vet[k]) k = j;
        }
        if(k != i) swap(vet[k], vet[i]);
    }
}