# -*- coding: utf-8 -*-

class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y

def dist(pa, pb):
    return ((pa.x - pb.x) ** 2 + (pa.y - pb.y) ** 2) ** 0.5

while True:
    entrada = input()
    if entrada == "0 0 0 0":
        break
    L, C, R1, R2 = map(int, entrada.split())
    diam1, diam2 = R1 * 2, R2 * 2
    distancia = dist(Point(R1, R1), Point((L - R2), (C - R2)))
    if diam1 <= L and diam1 <= C and diam2 <= L and diam2 <= C and distancia >= R1 + R2:
        print("S")
    else:
        print("N")