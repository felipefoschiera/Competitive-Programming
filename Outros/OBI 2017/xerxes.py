rodadas = int(input())
dario = xerxes = 0
for _ in range(rodadas):
    D, X = map(int, input().split())
    if X == (D + 1) % 5 or X == (D + 2) % 5:
        dario += 1
    else:
        xerxes += 1
    
if dario > xerxes:
    print("dario")
else:
    print("xerxes")
    