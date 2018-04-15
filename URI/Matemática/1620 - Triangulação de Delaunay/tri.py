# -*- coding: utf-8 -*-
while True:
    try:
        N = float(input())
        if N == 0:
            break
        I = N + N - 3
        X = (I - N) / N
        print("{:.6f}".format(X))
    except:
        break