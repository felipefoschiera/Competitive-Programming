# -*- coding: utf-8 -*-
# Felipe G. Foschiera 
# URI 2222 - Brincando com Conjuntos
T = int(input())
for _ in range(T):
    n = int(input())
    conjs = [None] * (n+1)
    for i in range(n):
        nums = list(map(int, input().split()))
        del nums[0]
        conjs[i] = set(nums)
    q = int(input())
    for _ in range(q):
        op, a, b = map(int, input().split())
        conj = conjs[a-1] & conjs[b-1] if op == 1 else conjs[a-1] | conjs[b-1]
        print(len(conj))