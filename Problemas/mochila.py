# Retorna o valor máximo que pode ser colocado em uma mochila de capacidade W

def knapSack(W , wt , val , n):
    # Base Case
    if n == 0 or W == 0 :
        return 0
    # Se o peso do n item é maior que a capacidade W,
    # então o item não pode ser incluído na solução
    # e retornamos o código com um item a menos
    if wt[n-1] > W:
        return knapSack(W , wt , val , n-1)
    # retorna o valor máximo entre dois casos:
    # (1) n item incluso
    # (2) nao incluso
    # val[n-1] é o valor do item, somado a nova mochila sem o peso do item
    return max(val[n-1] + knapSack(W-wt[n-1] , wt , val , n-1),
                knapSack(W , wt , val , n-1))
 

val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
print(knapSack(W , wt , val , n))
