
def dias(num):
    count = 0
    while num > 1:
        num /= 2.0
        count += 1    
    return count

def main():
    test_cases = int(input())
    for _ in range(test_cases):
        suprimento = float(input())
        print(dias(suprimento), 'dias')

main()