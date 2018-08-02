# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2290 - Números Apaixornados
while True:
    try:
        n = int(input())
        if n == 0: break
        nums = list(map(int, input().split()))
        nums.sort()
        i = 0
        cnt = 0
        alone = ""
        while True:
            if i < n-1 and nums[i] == nums[i+1]:
                i += 2
            else:
                alone += str(nums[i]) + " "
                cnt += 1
                if cnt == 2: break
                i += 1            
        alone = alone.strip()
        print(alone)

    except EOFError:
        break