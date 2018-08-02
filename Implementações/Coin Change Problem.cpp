#include <vector>
#define MAX 30000
using namespace std;
typedef long long ll;

ll ways[MAX];

void coinChange(){
    vector<int> coins;
    ways[0] = 1;
    for(auto c : coins)
        for(int i  = c; i <= MAX; i++)
            ways[i] += ways[i-c];
}