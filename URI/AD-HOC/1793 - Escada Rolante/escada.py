# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1793 - Escada Rolante
while True:
    n = int(input())
    if n == 0: break
    p, time = list(map(int, input().split())), 0
    for i in range(n): time += (10 if time == 0 else (10 if p[i] - p[i-1] > 10 else p[i] - p[i-1]))
    print(time)

