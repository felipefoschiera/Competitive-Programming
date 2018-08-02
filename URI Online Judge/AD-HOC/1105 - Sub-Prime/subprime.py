# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1105 - Sub-Prime
while True:
    B, N = map(int, input().split())
    if B == 0 and N == 0: break
    dinheiro = list(map(int, input().split()))
    for _ in range(N):
        dev, cred, valor = map(int, input().split())
        dinheiro[dev-1] -= valor
        dinheiro[cred-1] += valor
    sim = True
    for i in range(B):
        if dinheiro[i] < 0:
            sim = False
            break
    print("S" if sim else "N")