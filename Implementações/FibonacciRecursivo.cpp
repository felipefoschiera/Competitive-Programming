int pd[110]; // inicializar com -1

int fib(int n){
    if(n <= 1) return n;
    if(pd[n] != -1)
        return pd[n];
    return pd[n] = fib(n-1) + fib(n-2);
}