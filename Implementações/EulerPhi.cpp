// Gerar vector<ll> primes com o crivo de eratóstenes

ll eulerPhi(ll N) {
	ll i = 0, p = primes[i], ans = N;
	while (p * p <= N) {
		if (N % p == 0) ans -= ans / p;
		while (N % p == 0) N /= p;
		p = primes[++i];
	}
	if (N != 1) ans -= ans / N;
	return ans;
}