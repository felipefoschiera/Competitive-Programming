#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int main(){
    int A, B;
    while(scanf("%d %d", &A, &B), (A+B)){
        set<int> vA, vB;
        int v;
        for(int i = 0; i < A; i++){
            scanf("%d", &v);
            vA.insert(v);
        }
        for(int i = 0; i < B; i++){
            scanf("%d", &v);
            vB.insert(v);
        }
        int countA = 0, countB = 0;
        for(auto card : vA)
            if(vB.find(card) == vB.end()) countA++;
        for(auto card : vB)
            if(vA.find(card) == vA.end()) countB++;
        
        printf("%d\n", min(countA, countB));

    }
    return 0;
}