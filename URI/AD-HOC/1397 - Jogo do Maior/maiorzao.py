# -*- coding: utf-8 -*-

while True:
    try:
        rodadas = int(input())
        if rodadas == 0:
            break
        pa = pb = 0
        for _ in range(rodadas):
            a, b = map(int, input().split())
            if a > b:
                pa += 1
            elif b > a:
                pb += 1
        print(pa, pb)
    except:
        break