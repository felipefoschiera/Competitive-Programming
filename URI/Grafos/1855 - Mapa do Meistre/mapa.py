def pesquisaMapa(mapa, larg, alt):
    x, y = 0, 0
    direcao = ""
    if mapa[y][x] == "*":
        return True
    for _ in range(larg * alt):
        if mapa[y][x] == ">":
            direcao = "RIGHT"
        elif mapa[y][x] == "<":
            direcao = "LEFT"
        elif mapa[y][x] == "^":
            direcao = "UP"
        elif mapa[y][x] == "v":
            direcao = "DOWN"
        
        if direcao == "RIGHT":
            x += 1
        elif direcao == "LEFT":
            x -= 1
        elif direcao == "UP":
            y -= 1
        else:
            y += 1
        if x > larg - 1 or x < 0 or y > alt - 1 or y < 0:
            return False
        if mapa[y][x] == "*":
            return True
    return False
            


larg = int(input())
alt = int(input())
mapa = [[None for _ in range(larg)] for _ in range(alt)]
bau = False
for i in range(alt):
    linha = list(input())
    for j in range(len(linha)):
        if linha[j] == "*":
            bau = True
        mapa[i][j] = linha[j]

if not bau:
    print("!")
else:
    print("*") if pesquisaMapa(mapa, larg, alt) else print("!")