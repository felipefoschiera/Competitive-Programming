#include <vector>
using namespace std;
typedef vector<int> vi;

bool isSubsetSum(int coins[], int soma, int M)
{
    bool *possible = new bool[soma + 1]();
    possible[0] = true;
    for (int c = 0; c < M; c++)
    {
        for (int i = soma - coins[c]; i >= 0; i--)
        {
            if (possible[i])
            {
                possible[i + coins[c]] = true;
            }
        }
    }
    return possible[soma];
}


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