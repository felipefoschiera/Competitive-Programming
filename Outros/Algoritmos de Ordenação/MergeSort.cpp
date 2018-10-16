void merge(int vet[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = vet[i+l];
    for(int i = 0; i < n2; i++)
        R[i] = vet[i+m+1];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            vet[k] = L[i++];
        }else{
            vet[k] = R[j++];
        }
        k++;
    }
    while(i < n1){
        vet[k++] = L[i++];
    }
    while(j < n2){
        vet[k++] = R[j++];
    }
}

void mergesort(int vet[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergesort(vet, l, m);
        mergesort(vet, m+1, r);
        merge(vet, l, m, r);
    }
}