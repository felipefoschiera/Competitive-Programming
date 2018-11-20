# -*- coding: utf-8 -*-

while True:
    try:
        S, va, vb = map(int, input().split())
        if va > vb:
            diff_vel = va - vb
            print("{:.2f}".format(S / diff_vel))
        else:
            print("impossivel")
    except EOFError:
        break