#include <vector>
using namespace std;
typedef vector<int> vi;

class FenwickTree {
private: vi ft;
public:
    FenwickTree(int n) { ft.assign(n+1, 0); }
    int rsq(int b){
        int sum = 0;
        for(; b; b -= (b & (-b))) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0 : rsq(a-1)); 
    }
    void update(int k, int v){
        for(; k < (int)ft.size(); k += (k & (-k))) ft[k] += v; 
    }
};
