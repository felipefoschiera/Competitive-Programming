# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1104 - Troca de Cartas
while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    cartas_a = set(map(int, input().split()))
    cartas_b = set(map(int, input().split()))
    a_new = cartas_a - cartas_b
    b_new = cartas_b - cartas_a
    print(min(len(a_new), len(b_new)))

'''
https://www.geeksforgeeks.org/sets-in-python/
'''