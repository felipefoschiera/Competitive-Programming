test_cases = int(input())
for _ in range(test_cases):
    mineracao = input()
    stack = []
    count = 0
    for char in mineracao:
        if char == '<':
            stack.append(char)
        if char == '>' and stack:
            stack.pop()
            count += 1

    print(count)

    