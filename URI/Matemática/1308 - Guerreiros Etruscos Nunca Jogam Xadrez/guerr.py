# -*- coding: utf-8 -*-
# Guerreiros Etruscos Nunca Jogam Xadrez
T = int(input())
for _ in range(T):
    c = int(input())
    c *= 2
    a = b = 1
    delta = b * b - (4 * a * -c)
    x1 = (-b + (delta ** 0.5)) / (2 * a)
    print(int(x1))

