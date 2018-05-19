T = int(input())
for _ in range(T):
    s = input()
    sub = input()
    t1, t2 = len(s), len(sub)
    subseq = [[0 for _ in range(t1+1)] for _ in range(t2+1)]
    for i in range(t2+1): subseq[i][0] = 0
    for i in range(t1+1): subseq[0][i] = 1

    for i in range(1, t2+1):
        for j in range(1, t1+1):
            subseq[i][j] = subseq[i][j-1]
            if sub[i-1] == s[j-1]:
                subseq[i][j] += subseq[i-1][j-1]
    print(subseq[t2][t1])