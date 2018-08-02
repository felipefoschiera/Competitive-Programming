// UvA 10141 - Request for Proposal
// Felipe G. Foschiera
#include <iostream>
using namespace std;

int main(){
    int N, P, test = 1;
    while(cin >> N >> P){
        if(N == 0 && P == 0) break;
        cin.ignore();
        string s;
        for(int i = 0; i < N; i++) getline(cin, s);
        int mostReq = -1;
        string bestFit;
        int bestPrice;
        for(int i = 0; i < P; i++){
            string nome;
            double preco;
            int reqMet;
            getline(cin, nome);
            cin >> preco >> reqMet;
            cin.ignore();
            for(int i = 0; i < reqMet; i++) getline(cin, s);
            if(reqMet > mostReq){
                mostReq = reqMet; 
                bestFit = nome;
                bestPrice = preco;
            }else if(reqMet == mostReq && preco < bestPrice){
                bestPrice = preco;
                bestFit = nome;
            }
        }
        if(test != 1) cout << '\n';
        cout << "RFP #" << test++ << '\n' << bestFit << '\n';
    }
    return 0;   
}