while True:
    try:
        n = int(input())
        spaces = n + 3 - 1
        char_id = ord('A')
        between = -1
        mid = (n*2-1) / 2
        for i in range(1, n*2):
            print(" " * spaces + str(chr(char_id)), end = '')
            if between > -1:
                print(" " * between + str(chr(char_id)))
            else: print()
            char_id += 1 if i < mid else -1
            between += 2 if i < mid else -2
            spaces -= 1 if i < mid else -1
    except EOFError: break