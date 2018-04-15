# -*- coding: utf-8 -*-

MIN, MAX = 30, 60
while True:
    try:
        quant = int(input())
        botas = []
        for _ in range(quant):
            tamanho, lado = input().split()
            botas.append([int(tamanho), lado])
        count = 0
        for i in range(MIN, MAX+1):
            count += min(botas.count([i, 'E']), botas.count([i, 'D']))
        print(count)
    except:
        break
