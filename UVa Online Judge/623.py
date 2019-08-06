    
import math
while True:
    try:
        n = int(input())
        print(str(n) + "!")
        print(math.factorial(n))
    except EOFError:
        break