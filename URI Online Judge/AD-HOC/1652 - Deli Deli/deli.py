# -*- coding: utf-8 -*-
# URI 1652 - Deli Deli

def consoante(letra):
    vogais = ['a', 'e', 'i', 'o', 'u']
    if letra not in vogais:
        return True
    return False


irregulares = {}
fins = ['o', 's', 'ch', 'sh', 'x']
L, N = map(int, input().split())
for _ in range(L):
    sing, plural = input().split()
    irregulares[sing] = plural
for _ in range(N):
    palavra = input()
    if palavra in irregulares:
        print(irregulares[palavra])
    elif palavra[-1] == 'y' and consoante(palavra[-2]):
        print(palavra[:-1] + 'ies')
    elif palavra[-1] in fins or (palavra[-2] + palavra[-1]) in fins:
        print(palavra + 'es')
    else:
        print(palavra + 's')
    