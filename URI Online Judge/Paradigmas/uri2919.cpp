#include <cstdio>
#include <algorithm>

using namespace std;

int lis(int v[], int n){
    int tail[n];
    for(int i = 0; i < n; i++) tail[i] = 0;
    int length = 1;
    tail[0] = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] > tail[length-1])
            tail[length++] = v[i];
        else {
            auto it = find(tail, tail+length, v[i]);
            if(it != tail+length){
                continue;
            } 
            it = upper_bound(tail, tail+length, v[i]);
            *it = v[i];
        }
    }
    return length;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int v[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        printf("%d\n", lis(v, n));
    }
    return 0;
}