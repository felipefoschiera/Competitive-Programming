using namespace std;
#define MAX 11234
int LSOne(int N){
    return N & (-N);
}

int ft[MAX];

void update(int k, int v){
    while(k < MAX){
        ft[k] += v;
        k += LSOne(k);
    }
}

int rsq(int b){
    int soma = 0;
    while(b > 0){
        soma += ft[b];
        b -= LSOne(b);
    }
    return soma;
}

int rsq(int a, int b){
    return (a == 0 ? rsq(b) : rsq(b) - rsq(a-1));
}