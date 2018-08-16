#include <cstdio>
#include <string.h>
#include <vector>
#define MAX 112345

using namespace std;

typedef vector<int> vi;

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

int josephus(vi v){
    int prime_ind = 0;
    int m = primes[prime_ind] - 1;
    int ind = m;
    vi temp = v;
    while((int)temp.size() > 1){
        temp.erase(temp.begin() + ind);
        m = primes[++prime_ind];
        ind = (ind + m - 1) % (int)temp.size();
    }
    return temp[0];
    return 0;
}


int main(){
    int N;
    while(scanf("%d", &N), N){
        vi v(N);
        for(int i = 0; i < N; i++) v[i] = i+1;
        SieveOfEratosthenes();
        printf("%d\n", josephus(v));
    }
    return 0;
}