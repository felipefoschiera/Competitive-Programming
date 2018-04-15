# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2297 - Bafo

t = 1
while True:
    n = int(input())
    if n == 0: break
    a = b = 0
    for _ in range(n):
        al, be = map(int, input().split())
        a += al
        b += be
    print("Teste", t)
    t += 1
    print("Aldo" if a > b else "Beto")
    print()
    