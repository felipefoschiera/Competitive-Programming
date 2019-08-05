// Implementação retirada do macacário do ITA
matrix matrixExp(matrix a, int n) {
	if (n == 0) return id(a.size());
	matrix c = matrixExp(a, n/2);
	c = c*c;
	if (n%2 != 0) c = c*a;
	return c;
}

matrix fibo() {
	matrix c(2, vector<double>(2, 1));
	c[1][1] = 0;
	return c;
}

double fibo(int n) {
	matrix f = matrixExp(fibo(), n);
	return f[0][1];
}