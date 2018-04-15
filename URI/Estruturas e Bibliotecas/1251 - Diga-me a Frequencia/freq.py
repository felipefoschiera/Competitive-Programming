# -*- coding: utf-8 -*-
# URI 1251 - Diga-me a Frequencia
i = 0
while True:
    try:
        vals = {}    
        string = input()
        for c in string:
            if c not in vals:
                vals[c] = 1
            else:
                vals[c] += 1
        
        ords = []
        for k, v in vals.items():
            ords.append((ord(k), v))
        ords.sort(key = lambda l: (l[1], -l[0]))
        if i != 0:
            print()
        for o in ords:
            print(o[0], o[1])
        i += 1
    except EOFError:
        break