# -*- coding: utf-8 -*-

def dist(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

while True:
    entrada = input()
    if entrada == "0 0 0 0":
        break
    L, C, R1, R2 = map(int, entrada.split())
    diam1, diam2 = R1 * 2, R2 * 2
    distancia = dist(R1, R1, (L - R2), (C - R2))
    if diam1 <= L and diam1 <= C and diam2 <= L and diam2 <= C and distancia >= R1 + R2:
        print("S")
    else:
        print("N")