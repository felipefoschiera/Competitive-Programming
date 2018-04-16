# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1215 - Primeiro Dicionário de Andy
'''
Python 2 utilizado pois no Python3 dá Runtime Error.
'''

palavras = set()
while True:
    try:
        linha = raw_input() # -> única mudança do Python 3 para o Python 2 foi o raw_input.
        word = ""
        for c in range(len(linha)):
            if linha[c].isalpha():
                word += linha[c]
            else:
                if word:
                    palavras.add(word.lower())
                word = ""
            if c == len(linha) - 1:
                if word: palavras.add(word.lower())
            
    except EOFError:
        break

for p in sorted(palavras):
    print(p)