a = int(input())
b = int(input())
c = int(input())
andares = [0, 0, 0]
andares[0] = b * 2 + c * 4
andares[1] = a * 2 + c * 2
andares[2] = b * 2 + a * 4

andares.sort()
print(andares[0])