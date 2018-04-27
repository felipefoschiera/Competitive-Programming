# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1507 - Subsequências
def subs(ped, string):
    ind = 0
    for c in string:
        if c == ped[ind]:
            ind += 1
            if ind == len(ped): return 'Yes'
    return 'No'

for _ in range(int(input())):
    string, q = input(), int(input())
    for _ in range(q):
        st = input()
        print(subs(st, string))