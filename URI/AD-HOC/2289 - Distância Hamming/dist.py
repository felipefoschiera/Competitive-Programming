def countBits(n):
    count = 0
    while n:
        count += n & 1
        n >>= 1
    return count

while True:
    try:
        a, b = map(int, input().split())
        if a == 0 and b == 0:
            break
        n = a ^ b 
        print(countBits(n))
    except EOFError:
        break