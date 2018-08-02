# -*- coding: utf-8 -*-

class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y

def distancia_euclidiana(p1, p2):
    return ((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2) ** 0.5
while True:
    try:
        r1, x1, y1, r2, x2, y2 = map(int, input().split())
        A = Point(x1, y1)
        B = Point(x2, y2)
        d = distancia_euclidiana(A, B)
        if r1 >= d + r2:
            print("RICO")
        else:
            print("MORTO")
    except EOFError:
        break