import sys
for line in sys.stdin:
    parenteses = []
    wrong = 0
    
    for char in line:
        if char == '(':
            parenteses.append(char)
        if char == ')':
            if parenteses:
                parenteses.pop()
            else:
                wrong += 1
    if not parenteses and wrong == 0:
        print('correct')
    else:
        print('incorrect')