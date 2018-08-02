# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1944 - BRINDE FACE 2015
N = int(input())
vencedores = 0
stack = ["FACE"]
for _ in range(N):
    word = "".join(input().split())
    if not stack:
        stack.append("FACE")
    
    if word == stack[-1][::-1]:
        vencedores += 1
        stack.pop()
    else:
        stack.append(word)

print(vencedores)