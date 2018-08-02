quant_nums = int(input())
nums = {}
for _ in range(quant_nums):
    num = int(input())
    if num not in nums:
        nums[num] = 1
    else:
        nums[num] += 1
ordem = sorted(nums)
for n in ordem:
    print(n, 'aparece', nums[n], 'vez(es)')