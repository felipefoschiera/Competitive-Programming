abertas, acoes = list(map(int, input().split()))
for _ in range(acoes):
    acao = input()
    if acao == 'fechou':
        abertas += 1
    elif acao == 'clicou':
        abertas -= 1

print(abertas)