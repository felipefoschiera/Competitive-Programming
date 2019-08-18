#include <bits/stdc++.h>
using namespace std;

const int MAX = 410101;

int a[MAX], b[MAX];
int T[MAX], P[MAX];
int x[MAX], n;
int tptr, pptr;

void kmpPreprocess(){
    int i = 0, j = -1; x[0] = -1;
    while(i < pptr){
        while(j >= 0 && P[i] != P[j]) j = x[j];
        i++; j++;
        x[i] = j;
    }
}

bool kmpSearch(){
    int i = 0, j = 0;
    while(i < tptr){
        while(j >= 0 && T[i] != P[j]) j = x[j];
        i++; j++;
        if(j == pptr){
            return true;

        }
    }
    return false;
}


int main(){
    // ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    tptr = pptr = 0;

    for(int i = 1; i < n; i++){
        P[pptr++] = a[i] - a[i-1]; 
    }
    for(int i = 1; i < n; i++){
        T[tptr++] = b[i] - b[i-1];
    }   
    // repete o padrão com a diferença entre fim e início pois é circular
    T[tptr++] = 360000 + (b[0] - b[n-1]);
    for(int i = 1; i < n; i++){
        T[tptr++] = b[i] - b[i-1];
    }   
    kmpPreprocess();
    bool res = kmpSearch();
    cout << (res ? "possible" : "impossible") << '\n';
    
    return 0;
}