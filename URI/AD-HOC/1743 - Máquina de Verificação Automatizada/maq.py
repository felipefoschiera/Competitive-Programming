# -*- coding: utf-8 -*-

def Verificacao(X, Y):
    for i in range(len(X)):
        if X[i] == 0 and Y[i] == 0 or X[i] == 1 and Y[i] == 1:
            return "N"
    return "Y"

X = list(map(int, input().split()))
Y = list(map(int, input().split()))
print(Verificacao(X, Y))