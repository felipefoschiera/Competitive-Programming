# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2349 - Farm Robot
N, C, S = map(int, input().split())
comandos = list(map(int, input().split()))
pos = 1
count = 0
if pos == S:
    count += 1
for c in comandos:
    if c == 1:
        pos += 1
        if pos == N+1:
            pos = 1
    else:
        pos -= 1
        if pos == 0:
            pos = N
    if pos == S: count += 1

print(count)