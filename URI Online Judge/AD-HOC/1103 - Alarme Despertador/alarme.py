# -*- coding: utf-8 -*-

while True:
    h1, m1, h2, m2 = map(int, input().split())
    if h1 == 0 and m1 == 0 and h2 == 0 and m2 == 0:
        break
    horas = h2 - h1
    minutos = m2 - m1
    if minutos < 0:
        minutos += 60
        horas -= 1
    if horas < 0:
        horas += 24
    if h1 == h2 and m1 == m2:
        horas = 24
    minutos += horas * 60
    print(minutos)