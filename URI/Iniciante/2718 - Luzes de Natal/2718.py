# -*- coding: utf-8 -*-
quant = int(input())
for _ in range(quant):
    num = int(input())
    count = 0
    biggest_seq = 0
    binario = [int(x) for x in bin(num).lstrip('0b')]
    for num in binario:
        if num == 1:
            count += 1
            if count > biggest_seq:
                biggest_seq = count
        else:
            count = 0
    print(biggest_seq)