# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2568 - Ações
D, I, X, F = map(int, input().split())
if D % 2 == 1:
    if F % 2 == 1: I += X
else:
    if F % 2 == 1: I -= X
print(I)