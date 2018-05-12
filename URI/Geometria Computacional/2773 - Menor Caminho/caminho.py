# -*- coding: utf-8 -*-

class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y

def distancia(ptA, ptB):
    return ((ptA.x - ptB.x) ** 2 + (ptA.y - ptB.y) ** 2) ** 0.5

while True:
    try:
        Xi, Yi, Xf, Yf, V = map(int, input().split())
        inicio = Point(Xi, Yi)
        fim = Point(Xf, Yf)
        Xl, Yl, Xr, Yr = map(int, input().split())
        v1 = Point(Xl, Yl)
        v2 = Point(Xr, Yr)
        v3 = Point(Xr, Yl)
        v4 = Point(Xl, Yr)
        dist_vert1 = distancia(inicio, v1)
        dist_vert2 = distancia(inicio, v4)
        d_total_vert1 = dist_vert1 + distancia(v1, v3) + distancia(v3, fim)
        d_total_vert2 = dist_vert2 + distancia(v4, v2) + distancia(v2, fim)
        menor = min(d_total_vert1, d_total_vert2)
        t = menor / V
        print("{:.1f}".format(t))

    except EOFError: break