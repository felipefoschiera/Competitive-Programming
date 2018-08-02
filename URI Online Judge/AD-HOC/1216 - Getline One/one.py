# -*- coding: utf-8 -*-

soma = 0
count = 0   
while True:
    try:
        nome = input()
        dist = int(input())
        soma += dist
        count += 1
    except:
        break
print("{:.1f}".format(soma / count))