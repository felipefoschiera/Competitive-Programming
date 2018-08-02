// UvA 10038 - Jolly Jumpers
// Felipe G. Foschiera
#include <stdio.h>
#include <bitset>
using namespace std;
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int v[n];
        for(int i = 0; i < n; i++) scanf("%d", v+i);
        bitset<3123> diff;
        diff.reset();
        for(int i = 1; i < n; i++){
            int di = abs(v[i] - v[i-1]);
            diff[di] = 1;
        }
        bool ok = true;
        for(int i = 1; i < n; i++) if(diff[i] == 0) ok = false;

        printf(ok ? "Jolly\n" : "Not jolly\n");
    }
    return 0;
}