#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAX = 1000100;
bitset<MAX> bs;

vector<int> primes;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= MAX; i++){
        if(bs[i]){
            for(ll j = i*i; j <= MAX; j += i) bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}

int main(){
    sieve();
    int l, u;
    while(cin >> l >> u){
        int start = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
        int end = lower_bound(primes.begin(), primes.end(), u) - primes.begin();
        if(start == end){
            cout << "There are no adjacent primes.\n";
        }else{
            int cnt = 0;
            int cls1, cls2, distC = 1e9;
            int far1, far2, distF = 0;
            for(int i = start; primes[i] < u; i++){
                cnt++;
                int diff = primes[i+1]-primes[i];
                if(diff > distF){
                    distF = diff;
                    far1 = primes[i];
                    far2 = primes[i+1];
                }
                if(diff < distC){
                    distC = diff;
                    cls1 = primes[i];
                    cls2 = primes[i+1];
                }
            }
            cout << cls1 << "," << cls2 << " are closest, " << far1 << "," << far2 << " are most distant.\n";
        }
    
    }
    return 0;   
}