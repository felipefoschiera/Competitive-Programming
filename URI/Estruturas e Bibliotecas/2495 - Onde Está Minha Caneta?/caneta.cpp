// Felipe G. Foschiera
// URI 2495 - Onde Está Minha Caneta?
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> esta(n, 0);

        for (int i = 0; i < n - 1; i++) {
            int ind;
            scanf("%d", &ind);
            esta[ind - 1] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (esta[i] == 0) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }
    return 0;
}