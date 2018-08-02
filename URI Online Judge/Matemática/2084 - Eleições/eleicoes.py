# -*- coding: utf-8 -*-

N = int(input())
cand = list(map(int, input().split()))
cand.sort(reverse = True)
total_votos = sum(cand)
maior = cand.pop(0)

if maior > cand[0]:
    if maior >= total_votos * 0.45:
        print(1)
    else:
        if maior >= total_votos * 0.4:
            prim = False
            porc = maior / total_votos
            for i in range(N-1):
                porc_cand = cand[i] / total_votos
                
                diff = porc - porc_cand
                if diff < 0.1:
                    print(2)
                    prim = False
                    break
                else:
                    prim = True
            if prim:
                print(1)
        else:
            print(2)
else:
    print(2)