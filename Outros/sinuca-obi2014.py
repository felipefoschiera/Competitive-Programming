# OBI 2014 - Fase 2 - Junior
# Sinuca
# Felipe G. Foschiera
N = int(input())
bolas = list(map(int, input().split()))
for i in range(N-1):
    for j in range(N-1):
        if bolas[j] == bolas[j+1]:
            bolas[j] = 1
        else:
            bolas[j] = -1
print("preta" if bolas[0] == 1 else "branca")
