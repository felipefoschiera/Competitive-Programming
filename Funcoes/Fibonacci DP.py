MAX = 1000
f = [0] * MAX

def fib(n):
    if n == 0: return 0
    if n == 1 or n == 2:
        f[n] = 1
        return f[n]
    if f[n]: return f[n]
    # k = metade de n. n & 1 = n é ímpar
    if n & 1: k = (n+1) // 2
    else: k = n // 2
    '''
    fib(9) = 34
    f[9] = fib(5)*fib(5) + fib(4)*fib(4)
    f[9] = 5*5 + 3*3
    f[9] = 25+9 = 34
    '''
    if n&1:
        f[n] = fib(k) * fib(k) + fib(k-1) * fib(k-1)
    else:
        '''
        fib(10) = 55
        f[10] = (2 * fib(4)) + fib(5)) * fib(5)
        f[1] = (2*3 + 5) * 5
        '''
        f[n] = (2 * fib(k-1) + fib(k)) * fib(k)
    return f[n]

while True:
    n = int(input())
    print(fib(n))
    print(f)
