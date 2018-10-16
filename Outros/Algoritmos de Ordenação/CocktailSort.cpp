#include "funcoes.cpp"

void cocktailsort(int vet[], int n){
    int in = 0, end = n-1;
    while(in <= end){
        bool troca = false;
        for(int i = in; i < end; i++){
            if(vet[i] > vet[i+1]){
                swap(vet[i], vet[i+1]);
                troca = true;
            }
        }
        end--;
        for(int i = end; i > in; i--){
            if(vet[i] < vet[i-1]){
                swap(vet[i], vet[i-1]);
                troca = true;
            }
        }
        in++;
        if(!troca) return;
    }
}
