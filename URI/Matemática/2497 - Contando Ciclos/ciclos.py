# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2497 - Contando Ciclos
i = 1
while True:
    n = int(input())
    if n == -1: break
    print("Experiment {}: {} full cycle(s)".format(i, n // 2))
    i += 1