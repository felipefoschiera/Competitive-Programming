T = int(input())
for _ in range(T):
    red = green = blue = 0
    qt = int(input())
    for _ in range(qt):
        a, b = input().split()
        if a == 'G':
            if b == 'R':
                green += 1
            else:
                green += 2
        elif a == 'R':
            if b == 'G':
                red += 2
            else:
                red += 1
        else:
            if b == 'G':
                blue += 1
            else:
                blue += 2
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
