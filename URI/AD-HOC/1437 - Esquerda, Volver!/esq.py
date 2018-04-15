# -*- coding: utf-8 -*-

while True:
    N = int(input())
    if N == 0:
        break
    passos = list(input())
    mov = 0
    for p in passos:
        if p == "D":
            mov += 1
        else:
            mov -= 1
    pos = mov % 4
    if pos == 0:
        print("N")
    elif pos == 2 or pos == -2:
        print("S")
    elif pos == -1 or pos == 3:
        print("O")
    else:
        print("L")