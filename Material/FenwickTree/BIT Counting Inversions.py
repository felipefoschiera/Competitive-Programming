# Contar números de inversões/swaps para ordenar uma lista utilizando BIT (Binary Indexed Tree).

# Ler https://goo.gl/Kne1aa

def inversions(A): # A sendo a lista original de valores
	res = 0
	bit = BIT(max(A)+1) # Cria uma BIT com tamanho igual ao max_valor + 1
	for i in range(N): // Para N = número de elementos
		res += i - bit.rsq(A[i])
		bit.update(A[i], 1)
	return res	

# ou

for i, v in enumerate(A):
		res += i - bit.sum(v)
		bit.add(v, 1)
	return res

