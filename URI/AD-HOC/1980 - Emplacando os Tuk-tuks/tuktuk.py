# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1890 - Emplacando os Tuk-tuks
T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        print(0)
    else:
        total = 26**n * 10**m
        print(total)