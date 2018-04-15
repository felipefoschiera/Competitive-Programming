# -*- coding: utf-8 -*-

while True:
    try:
        num = input()
        while "#" not in num:
            num += input()
        num = [x for x in num if x.isdigit()]
        num = ''.join(num)
        
        inteiro = int(num, 2)
        if inteiro % 131071 == 0:
            print("YES")
        else:
            print("NO")
    except EOFError:
        break