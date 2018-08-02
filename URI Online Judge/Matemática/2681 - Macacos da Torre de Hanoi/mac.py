# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2681 - Macacos da Torre de Hanoi
MOD = 86400
N = int(input())
movimentos = pow(2, N, MOD) - 1
h = movimentos / 3600
movimentos %= 3600
m = movimentos / 60
movimentos %= 60

print("{:02}:{:02}:{:02}".format(int(h), int(m), movimentos))
