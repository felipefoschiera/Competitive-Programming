#include "funcoes.cpp"

void bubblesort(int vet[], int n){
    for(int i = 0; i < n-1; i++){
        bool troca = false;
        for(int j = 0; j < n-i-1; j++){
            if(vet[j] > vet[j+1]){
                swap(vet[j], vet[j+1]);
                troca = true;
            }
        }
        if(!troca) return;
    }
}