# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2554 - Pizza Antes de BH
while True:
    try:
        n, m = map(int, input().split())
        data_select = ""
        select = False
        for _ in range(m):
            nums = input().split()
            data = nums.pop(0)
            podem = 0
            for i in range(n):
                if nums[i] == '1': podem += 1
            if podem == n and not select:
                data_select = data
                select = True
        print(data_select if data_select else "Pizza antes de FdI")
    except EOFError:
        break