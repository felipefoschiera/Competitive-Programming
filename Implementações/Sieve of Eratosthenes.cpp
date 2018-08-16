// Gera primos até MAX
#include <vector>
#include <string.h>
#define MAX 112345
using namespace std;

vector<int> primes;

void SieveOfEratosthenes(){
	bool prime[MAX];
	memset(prime, true, sizeof prime);
	for(int p = 2; p <= MAX; p++){
		if(prime[p] == true){
            primes.push_back(p);
            if(primes.size() == 3600) break;
			for(int i = p*2; i <= MAX; i += p)
        		prime[i] = false;
		}
	}
}