def mdc(a, b):
    resto = None
    while resto is not 0:
        resto = a % b
        a = b
        b = resto
    return a

def Verif(a, b, c):
    result = "tripla"
    if a * a == b * b + c * c:
        result += " pitagorica"
        mdcAB = mdc(a, b)
        mdc_c = mdc(mdcAB, c)
        if mdc_c == 1:
            result += " primitiva"
    return result
while True:
    try:
        nums = list(map(int, input().split()))
        nums.sort(reverse = True)
        a, b, c = nums
        print(Verif(a, b, c))
    except:
        break