while True:
    try:
        s = input().split()
        cnt = 0
        for word in s:
            letra = False
            for ch in word:
                if ch.isalpha():
                    letra = True
            if letra:
                cnt += 1
        print(cnt)
    except EOFError:
        break