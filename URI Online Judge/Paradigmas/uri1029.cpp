#include <stdio.h>
#include <string.h>

int memo[41], f[41];

int fib(int n){
    if(f[n] == -1){
        if(n <= 1) f[n] = n;
        else f[n] = fib(n-1) + fib(n-2);
    }
    return f[n];
}

int calls(int n){
    if(memo[n] == -1){
        if(n <= 1) memo[n] = 1;
        else memo[n] = calls(n-1) + calls(n-2) + 1;
    }
    return memo[n];
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(memo, -1, sizeof memo);
        memset(f, -1, sizeof f);
        int n;
        scanf("%d", &n);
        printf("fib(%d) = %d calls = %d\n", n, calls(n)-1, fib(n));
    }
    return 0;
}
