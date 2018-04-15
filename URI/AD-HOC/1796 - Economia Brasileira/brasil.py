# -*- coding:utf-8 -*-

quant = int(input())
votos = list(map(int, input().split()))
if votos.count(1) >= quant / 2:
    print("N")
else:
    print("Y")