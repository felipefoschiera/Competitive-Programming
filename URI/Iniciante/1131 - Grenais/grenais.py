# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1131 - Grenais
inter = gremio = empates = 0
n = 0
while True:
    try:

        gi, gg  = map(int, input().split())
        if gi > gg: inter += 1
        elif gi == gg: empates += 1
        else: gremio += 1
        n += 1
        op = int(input())
        print("Novo grenal (1-sim 2-nao)")
        if op == 2: break
    except EOFError: break

print(n, 'grenais')
print("Inter:{}".format(inter))
print("Gremio:{}".format(gremio))
print("Empates:{}".format(empates))
if inter > gremio:
    print("Inter venceu mais")
elif inter == gremio:
    print("Nao houve vencedor")
else:
    print("Gremio venceu mais")