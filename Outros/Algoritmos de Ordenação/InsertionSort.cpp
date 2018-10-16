#include "funcoes.cpp"

void insertionsort(int vet[], int n){
    for(int i = 1; i < n; i++){
        int j = i-1;
        int chave = vet[i];
        while(j >= 0 && vet[j] > chave){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = chave;
    }
}