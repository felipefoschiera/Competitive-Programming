# -*- coding: utf-8 -*-
N = int(input())
for _ in range(N):
    codigo = list(input())
    a, letra, b = codigo
    a, b = int(a), int(b)
    if a == b:
        print(a * b)
    else:
        if letra.islower():
            print(a + b)
        else:
            print(b - a)
