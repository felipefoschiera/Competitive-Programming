# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1537 - Fila do Banco
MOD = 1000000009
fats = [0] * 100001
fats[3] = 1
for i in range(4, 100001):
    fats[i] = (i * fats[i-1]) % MOD

while True:
    n = int(input())
    if n == 0: break
    print(fats[n])