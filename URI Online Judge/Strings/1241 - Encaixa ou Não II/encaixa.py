test_cases = int(input())
for _ in range(test_cases):
    num, end = input().split()
    if num[len(num) - len(end):] == end:
        print('encaixa')
    else:
        print('nao encaixa')