# -*- coding: utf-8 -*-

qt = int(input())
preco_total = dias = peso_total = 0
for i in range(qt):
    preco = float(input())
    frutas = input().split()
    qt_frutas = len(frutas)
    peso_total += qt_frutas
    preco_total += preco
    dias += 1
    print('day {}: {} kg'.format(dias, qt_frutas))
kg_dia = peso_total / dias
print("{:.2f} kg by day".format(kg_dia))
preco_dia = preco_total / dias
print("R$ {:.2f} by day".format(preco_dia))