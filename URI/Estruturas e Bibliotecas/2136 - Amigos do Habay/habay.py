# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2136 - Amigos do Habay
selecionado = ""
sim, nao = set(), set()
while True:
    line = input()
    if line == "FIM": break
    nome, estado = line.split()
    if estado == "YES":
        sim.add(nome)
        if len(nome) > len(selecionado): selecionado = nome
    else:
        nao.add(nome)

for n in sorted(sim): print(n)
for n in sorted(nao): print(n)
print()
print("Amigo do Habay:")
print(selecionado)