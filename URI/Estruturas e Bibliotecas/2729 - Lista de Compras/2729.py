tests = int(input())
for _ in range(tests):
    palavras = input().split()
    unicas = []
    for pal in palavras:
        if pal not in unicas:
            unicas.append(pal)
    
    unicas.sort()
    print(' '.join(unicas))