# -*- coding:utf-8 -*-
# URI 2338 - Morse
# Felipe G. Foschiera


morse_dict = {
    '=.===': 'a',
    '===.=.=.=': 'b',
    '===.=.===.=': 'c',
    '===.=.=': 'd',
    '=': 'e',
    '=.=.===.=': 'f',
    '===.===.=': 'g',
    '=.=.=.=': 'h',
    '=.=': 'i',
    '=.===.===.===': 'j',
    '===.=.===': 'k',
    '=.===.=.=': 'l',
    '===.===': 'm',
    '===.=': 'n',
    '===.===.===': 'o',
    '=.===.===.=': 'p',
    '===.===.=.===': 'q',
    '=.===.=': 'r',
    '=.=.=': 's',
    '===': 't',
    '=.=.===': 'u',
    '=.=.=.===': 'v',
    '=.===.===': 'w',
    '===.=.=.===': 'x',
    '===.=.===.===': 'y',
    '===.===.=.=': 'z'
}

t = int(input())
for _ in range(t):
    resultado = ""
    palavras = input().split('.......')
    for p in range(len(palavras)):
        letras = palavras[p].split('...')
        for l in letras:
            resultado += morse_dict[l]
        if p != len(palavras) - 1:
            resultado += ' '
    print(resultado)