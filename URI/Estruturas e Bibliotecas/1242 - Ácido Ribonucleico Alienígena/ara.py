# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1242 - Ácido Ribonucleico Alienígena
rel = { 'B': 'S', 'S': 'B', 'F': 'C', 'C': 'F' }
while True:
    try:
        seq = list(input())
        pile, count = [seq.pop(0)], 0
        for el in seq:
            if pile and pile[-1] == rel[el]:
                count += 1
                pile.pop()
            else: pile.append(el)
        print(count)
    except EOFError: break
