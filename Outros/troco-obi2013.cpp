#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;

vi moedas;

bool isSubsetSum(int sum, int n){
    vector<bool> possible(sum+1, false);
    possible[0] = true;
    for(auto c : moedas)
        for(int i = sum-c; i >= 0; i--)
            if(possible[i])
                possible[i+c] = true;
    return possible[sum]; 
}

int main(){
    int V, M, i, s;
    scanf("%d %d", &V, &M);
    for(i = 0; i < M; i++){
        scanf("%d", &s);
        moedas.push_back(s);
    }
    bool ans = isSubsetSum(V, M);
    printf(ans ? "S\n" : "N\n");
    return 0;
}