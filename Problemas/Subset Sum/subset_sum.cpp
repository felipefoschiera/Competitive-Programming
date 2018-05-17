#include <vector>
using namespace std;
typedef vector<int> vi;

vi moedas;

bool isSubsetSum(int sum){
    vector<bool> possible(sum+1, false);
    possible[0] = true;
    for(auto c : moedas)
        for(int i = sum-c; i >= 0; i--)
            if(possible[i])
                possible[i+c] = true;
    return possible[sum]; 
}