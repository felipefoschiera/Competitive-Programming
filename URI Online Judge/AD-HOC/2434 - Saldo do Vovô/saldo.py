# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2434 - Saldo do Vovô
N, val = map(int, input().split())
menor_val = val
for _ in range(N):
    val += int(input())
    menor_val = min(menor_val, val)
print(menor_val)