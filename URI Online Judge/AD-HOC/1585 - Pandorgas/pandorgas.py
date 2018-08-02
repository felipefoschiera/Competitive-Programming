# -*- coding: utf-8 -*-

pipas = int(input())
for _ in range(pipas):
    a, b = map(int, input().split())
    area = int((a * b) / 2)
    print(area, 'cm2')