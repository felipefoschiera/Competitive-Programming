/**
 *  Menor número de swaps para ordenar sequência sem ser com elementos adjacentes.
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(int arr[], int n){
    pair<int, int> pos[n];
    for(int i = 0; i < n; i++){
        pos[i].first = arr[i];
        pos[i].second = i;
    }
    sort(pos, pos+n);
    vector<bool> visited(n, false);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] || pos[i].second == i) continue;
        int cycle_size = 0;
        int j = i;
        while(!visited[j]){
            visited[j] = 1;
            j = pos[j].second;
            cycle_size++;          
        }
        ans += cycle_size - 1;
    }
    return ans;
}

int main(){
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int seq[n];
        for(int i = 0; i < n; i++){
            scanf("%d", seq+i);
        }
        printf("%d\n", minSwaps(seq, n));
    }
    return 0;   
}