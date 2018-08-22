#include <cstdio>
#define MAX 112345
#define SQ 335

int N;
int b[SQ], A[MAX];

int query(int l, int r){
    int soma = 0;
    for(int i = l/SQ+1; i < r/SQ; i++)
        soma += b[i];
    if(l/SQ != r/SQ){
        for(int i = l; i < (r/SQ+1)*SQ; i++) soma += A[i];
        for(int i = r/SQ*SQ; i <= r; i++) soma += A[l];
    }else{
        for(int i = l; i <= r; i++) soma += A[i];
    }
    return soma;
}

void update(int k, int v){
    b[k/SQ] -= A[k];
    A[k] = v;
    b[k/SQ] += A[v];
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &A[i]);
        b[i/SQ] += A[i];
    }
    int Q, op, a, b;
    scanf("%d", &Q);
    while(Q--){
        scanf("%d %d %d", &op, &a, &b);
        if(op == 1) printf("%d\n", query(a, b));
        else if(op == 2) update(a, b);
    }
    return 0;
}