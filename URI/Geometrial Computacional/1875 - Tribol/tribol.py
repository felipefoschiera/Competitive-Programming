T = int(input())
for _ in range(T):
    red = green = blue = 0
    qt = int(input())
    for _ in range(qt):
        a, b = input().split()
        if a == 'G':
            green += (1 if b == 'R' else 2)
        elif a == 'R':
            red += (2 if b == 'G' else 1)
        else:
            blue += (1 if b == 'G' else 2)
            
    maior = max(red, green, blue)
    if red == green == blue:
        print("trempate")
    elif (maior == red and maior == green) or (maior == green and maior == blue) or (maior == red and maior == blue):
        print("empate")
    else:
        maior = max(red, green, blue)
        if maior == red:
            print("red")
        elif maior == green:
            print("green")
        else:
            print("blue")
