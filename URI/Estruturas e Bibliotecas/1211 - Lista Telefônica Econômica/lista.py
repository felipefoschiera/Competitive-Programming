# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1211 - Lista Telefônica Econômica
while True:
    try:
        n, econ = int(input()), 0
        strings = []
        for i in range(n):
            strings.append(input())
        strings.sort()
        curr = strings.pop(0)
        while strings:
            st = strings[0]
            for c in range(len(curr)):
                if curr[c] == st[c]: econ += 1
                else: break
            curr = strings.pop(0) 
        print(econ)
    except EOFError: break