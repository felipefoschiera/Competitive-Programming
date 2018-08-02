# -*- coding: utf-8 -*-

while True:
    try:
        quant_merg, quant_volt = list(map(int, input().split()))
        mergulharam = set(map(int, input().split()))
        if quant_merg == quant_volt:
            print('*')
        else:
            for i in range(1, quant_merg + 1):
                if i not in mergulharam:
                    print(i, end = ' ')
            print()
    except:
        break
        