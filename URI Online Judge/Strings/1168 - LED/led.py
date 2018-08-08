# -*- coding: utf-8 -*-

leds = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6]
for _ in range(int(input())):
    v, ans = input(), 0
    for d in v: ans += leds[ord(d) - ord('0')]
    print(ans, 'leds')