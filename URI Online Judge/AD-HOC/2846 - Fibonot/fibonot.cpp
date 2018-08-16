#include <stdio.h>
#define MAX 1123456
typedef long long ll;

int fib[MAX];
ll f[MAX];

ll naoFib[MAX];

void fibs(){
    fib[0] = fib[1] = 1;
    f[0] = 0LL;
    f[1] = 1LL;
    for(int i = 2; i < 30; i++){
        f[i] = f[i-1] + f[i-2];
        fib[f[i]] = 1;
    }
    int cont = 0;
    for(int i = 4; i < MAX; i++){
        if(!fib[i]){
            naoFib[cont] = i;
            cont++;
        }
    }
}


int main(){
    fibs();
    int k;
    scanf("%d", &k);
    printf("%lld\n", naoFib[k-1]);
    
    return 0;   
}