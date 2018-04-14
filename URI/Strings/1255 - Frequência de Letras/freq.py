test_cases = int(input())
for _ in range(test_cases):
    frase = list(input().lower())
    chars_freq = []
    for char in set(frase):
        chars_freq.append([frase.count(char), char])
        chars_freq = sorted(chars_freq, key=lambda y: (-y[0], y[1]))
    if chars_freq[0][0] != chars_freq[1][0]:
        print(chars_freq[0][1])
    else:
        i = 1
        print(chars_freq[0][1], end="")
        while chars_freq[0][0] == chars_freq[i][0]:
            print(chars_freq[i][1], end = "")
            if i != len(chars_freq):
                i += 1
        
    