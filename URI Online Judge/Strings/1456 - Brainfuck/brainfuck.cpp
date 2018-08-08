#include <iostream>
#include <string.h>
#include <stack>
#include <unordered_map>
using namespace std;


string s, ops;
char vetor[30000];
unordered_map<int, int> loops;
int op_pointer, vetor_pointer, input_pointer, string_size, op_size, start_operation_index;

void executaOperacao(char op){
    if(op == '+') vetor[vetor_pointer]++;
    if(op == '-') vetor[vetor_pointer]--;
    if(op == '>') vetor_pointer++;
    if(op == '<') vetor_pointer--;
    if(op == '.')
            cout << (vetor[vetor_pointer]);
    if(op == ','){
        if(input_pointer >= string_size) vetor[vetor_pointer] = 0;
        else {
            vetor[vetor_pointer] = (int)s[input_pointer];
            input_pointer++;
        }
    }
    if(op == '#'){
        for(int i = 0; i < 10; i++) cout << ((char)vetor[i]);
    }
    if(op == '['){
        if(vetor[vetor_pointer] == 0){
            op_pointer = loops[op_pointer] + 1;
            return;
        }
    }
    if(op == ']'){
        op_pointer = loops[op_pointer];
        return;
    }
    op_pointer++;

}   

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> s;
        cin >> ops;
        string_size = s.length(), op_size = ops.length();
        op_pointer = 0, vetor_pointer = 0, input_pointer = 0;
        memset(vetor, 0, sizeof vetor);
        stack<int> loopStack;
        loops.clear();
        for(int i = 0; i < op_size; i++){
            if(ops[i] == '['){
                loopStack.push(i);
            }else if(ops[i] == ']'){
                int l = loopStack.top();
                loopStack.pop();
                loops[i] = l;
                loops[l] = i;
            }
        }
        cout << "Instancia " << t << '\n';
        while(true){
            char op = ops[op_pointer];
            executaOperacao(op);
           if(op_pointer >= op_size) break;
            
        }
        
        cout << '\n';
        cout << '\n';
    }
    return 0;
}