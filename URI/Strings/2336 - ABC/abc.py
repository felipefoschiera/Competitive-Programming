# -*- coding: utf-8 -*-
# URI 2336 - ABC
# Felipe G. Foschiera

from string import ascii_uppercase

MAX = 1001

letras = {}
for i, l in enumerate(ascii_uppercase):
    letras[l] = i

MOD = 1000000007

memo = [0] * MAX
for i in range(MAX):
    memo[i] = pow(26, i, MOD)

while True:
    try:
        string = input()
        num = 0
        size = len(string)
        for i in range(size-1, -1, -1):
            num += (letras[string[i]] * memo[size-1-i]) % MOD
            num %= MOD
        print(num)
    except EOFError:
        break