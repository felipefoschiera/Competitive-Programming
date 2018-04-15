# -*- coding: utf-8 -*-
while True:
    try:
        numeros = list(map(int, input().split()))
        a, b, c = numeros
        if a == b and a != c:
            print("C")
        elif a == c and a != b:
            print("B")
        elif b == c and a != b:
            print("A")
        else:
            print("*")
    except:
        break