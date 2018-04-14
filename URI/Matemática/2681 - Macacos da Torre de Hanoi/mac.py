MOD = 86400

def binpow(x, n):
    if n == 0: return 1
    y = 1
    while n > 1:
        if n&1:
            y *= x % MOD
            y %= MOD
        x *= x % MOD
        x %= MOD
        n //= 2
    return (x%MOD) * (y%MOD)

N = int(input())
movimentos = (binpow(2, N) - 1) % MOD
h = movimentos / 3600
movimentos %= 3600
m = movimentos / 60
movimentos %= 60

print("{:02}:{:02}:{:02}".format(int(h), int(m), movimentos))
