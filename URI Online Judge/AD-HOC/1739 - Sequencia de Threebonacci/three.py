# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1739 - Sequência de Threebonacci
fibs = [1]
a, b = 1, 1
for _ in range(90):
    f = a + b
    a = b
    b = f
    fibs.append(b)
trib = []
for n in fibs:
    if '3' in str(n) or n % 3 == 0:
        trib.append(n)
while True:
    try:
        n = int(input())
        print(trib[n-1])
    except EOFError:
        break