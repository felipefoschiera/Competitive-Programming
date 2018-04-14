while True:
    try:
        N = int(input())
        H, C, L = map(int, input().split())
        hip = (C * C + H * H) ** 0.5
        area = hip * N * L
        print("{:.4f}".format(area / 10000))
    except EOFError:
        break