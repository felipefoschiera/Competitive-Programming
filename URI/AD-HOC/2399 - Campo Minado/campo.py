# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2399 - Campo Minado
N = int(input())
minas = [0] * N
for i in range(N):
    m = int(input())
    minas[i] = m

for i in range(N):
    ct = 0
    if minas[i] == 1: ct += 1
    if i < N - 1:
        if minas[i+1] == 1: ct += 1
    if i > 0:
        if minas[i-1] == 1: ct += 1
    print(ct)
