def ehPalindromo(str):
    return str == str[::-1]
    # str[::-1] é a string reversa


# Palíndromo recursivo
def isPalindrome(str):
    if len(str) == 0 or len(str) == 1: return True
    if str[0] != str[-1]: return False
    return isPalindrome(str[1:-1])

 