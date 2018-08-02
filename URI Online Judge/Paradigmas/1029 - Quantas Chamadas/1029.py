# -*- coding: utf-8 -*-
memo = [None for i in range(40)]
numeros_fib = []

def fib(n):
    if memo[n] == None:
        if n <= 1:
            memo[n] = n
        else:
            memo[n] = fib(n-1) + fib(n-2)
    return memo[n]

for i in range(40):
    numeros_fib.append(fib(i))

memo_calls = [None for i in range(40)]
def calls(n):
    if memo_calls[n] == None:
        if n <= 1:
            memo_calls[n] = 1
        else:
            memo_calls[n] = calls(n-1) + calls(n-2) + 1   
    return memo_calls[n]

tests = int(input())
for _ in range(tests):
    num = int(input())
    print("fib({}) = {} calls = {}".format(num, calls(num) - 1, numeros_fib[num]))