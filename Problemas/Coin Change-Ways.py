MAX = 30000
ways = [0] * MAX
changeTypes = [1, 2, 3]
ways[0] = 1
for c in changeTypes:
    for i in range(c, MAX):
        ways[i] += ways[i-c]

while True:
    N = int(input())
    if ways[N] == 1:
        print("There is only 1 way to produce", N, "cents change.")
    else:
        print("There are", ways[N], "ways to produce", N, "cents change.")
