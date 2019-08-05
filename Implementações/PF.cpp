
vector<ll> primes; // gerar com o crivo de eratóstenes

vector<ll> primeFactors(ll N) {
	vector<int> factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) { 
		while (N % PF == 0) {
			N /= PF;
			factors.push_back(PF);
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) factors.push_back(N);
	return factors;
}