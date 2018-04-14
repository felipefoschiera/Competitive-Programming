A, op, B = input().split()
A = A.replace('7', '0')
B = B.replace('7', '0')

calc = 0
if op == '+':
    calc = int(A) + int(B)
else:
    calc = int(A) * int(B)

calc = str(calc)
calc = calc.replace('7', '0')
calc = int(calc)
print(calc)