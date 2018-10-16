#include "funcoes.cpp"

void quicksort(int vet[], int low, int high){
    int i = low, j = high;
    int pivo = vet[(low+high)/2];
    while(i <= j){
        while(vet[i] < pivo && i < high) i++;
        while(vet[j] > pivo && j > low) j--;
        if(i <= j){
            swap(vet[i++], vet[j--]);
        }
    }
    if(j > low) quicksort(vet, low, j+1);
    if(i < high) quicksort(vet, i, high);
}
