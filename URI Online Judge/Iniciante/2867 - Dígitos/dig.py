n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    c = pow(a, b)
    print(len(str(c)))