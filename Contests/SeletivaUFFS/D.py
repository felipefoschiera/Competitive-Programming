n = int(input())
MOD = 86400
res = pow(2, n, MOD) - 1
hrs = res // 3600
res %= 3600
mnt = res // 60
res %= 60
print(hrs, mnt, res)