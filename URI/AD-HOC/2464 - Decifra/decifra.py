# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2464 - Decifra
traducao = {}
letras = input()
for i in range(26):
    traducao[chr(i+97)] = letras[i]
frase = input()
new = ""
for c in frase:
    new += traducao[c]
print(new)