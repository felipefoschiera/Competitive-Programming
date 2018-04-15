# -*- coding: utf-8 -*-

def Tautograma(frase):
    palavras = frase.lower().split()
    iniciais = []
    for p in palavras:
        iniciais.append(p[0])
    first = iniciais[0]
    if iniciais.count(first) == len(iniciais):
        return "Y"
    return "N"

while True:
    frase = input()
    if frase == '*':
        break
    print(Tautograma(frase))