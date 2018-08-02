# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2496 - A Única Chance
from string import ascii_uppercase

def mudancas(seq):
    cnt = 0
    i = 0
    for c in seq:
        if c != ascii_uppercase[i]:
            cnt += 1
        i += 1
    return cnt < 3

T = int(input())
for _ in range(T):
    n = int(input())
    seq = input()
    print("There are the chance." if mudancas(seq) else "There aren't the chance.")