while True:
    try:
        n = int(input())
        i = c = 1
        while i % n != 0:
            i = (10 * i + 1) % n
            c += 1
        print(c)
    except EOFError:
        break
