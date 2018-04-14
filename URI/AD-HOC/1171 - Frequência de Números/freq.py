quant_nums = int(input())
nums = []
for _ in range(quant_nums):
    num = int(input())
    nums.append(num)

for num in sorted(list(set(nums))):
    print(num, "aparece", nums.count(num), "vez(es)")