quant = int(input())
for _ in range(quant):
    palavra = input()
    a = b = c = d = e = ''
    a, b, c = palavra[0], palavra[1], palavra[2]
    if len(palavra) == 5:
        d, e = palavra[3], palavra[4]
    if palavra == 'one' or a == 'o' and c == 'e' or a == 'o' and b == 'n' or b == 'n' and c == 'e':
        print(1)
    elif palavra == 'two' or a == 't' and c == 'o' or a == 't' and b == 'w' or b == 'w' and c == 'o':
        print(2)
    elif palavra == 'three' or b == 'h' and c == 'r' and d == 'e' and e == 'e' or a == 't' and c == 'r' and d == 'e' and e == 'e' or a == 't' and b == 'h' and d == 'e' and e == 'e' or a == 't' and b == 'h' and c == 'r' and e == 'e' or a == 't' and b == 'h' and c == 'r' and d == 'e':
        print(3)

