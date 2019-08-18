#include <stdio.h>
#include <set>
#include <map>
using namespace std;

const int MAX = 112345;

int team[MAX];

map<int, set<int> > familiasTime;

int main(){
    int N, F;
    scanf("%d %d", &N, &F);
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    team[1] = a;
    familiasTime[a].insert(1);
    for(int i = 2; i <= N; i++){
        team[i] = (b * team[i-1] + c) % F;
        familiasTime[team[i]].insert(i);
    }
    int M;
    scanf("%d", &M);
    while(M--){
        int I, E;
        scanf("%d %d", &I, &E);
        familiasTime[team[I]].erase(I);
        familiasTime[E].insert(I);
        team[I] = E;
        int distcw, distccw;
        auto it = familiasTime[E].find(I);
        if(it == familiasTime[E].begin()){
            it = familiasTime[E].end();
            it--;
            if((*it) != I)
                distccw = N - (*it) + I;
            else
                distccw = N; 
        }else{
            it--;
            distccw = I - (*it);
        }
        auto it2 = familiasTime[E].find(I);
        if(it2 != familiasTime[E].end() && (it2 == --familiasTime[E].end())){
            it2 = familiasTime[E].begin();
            if((*it2) != I){
                distcw = N - I + (*it2);
            }else{
                distcw = N;
            }
        }else{
            it2++;
            distcw = (*it2) - I;
        }
        printf("%d %d\n", distccw, distcw);
    }
 
    return 0;
}