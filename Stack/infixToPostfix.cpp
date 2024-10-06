#include <bits/stdc++.h>
using namespace std;

int precedence(char ope){
    if(ope == '+' || ope == '-') return 1;
    if(ope == '*' || ope == '/') return 2;
    if(ope == '^') return 3;
    return 0;
}

string infixToPostfix(string infix){
    stack<char>ope;
    string postfix = "";
    for(int i = 0; i < infix.size(); i++){
        if(infix[i] == '('){
            ope.push(infix[i]);
        }else if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9')){
            postfix += infix[i];
        }else if(infix[i] == ')'){
            while(ope.top() != '('){
                postfix += ope.top();
                ope.pop();
            }
            ope.pop();
        }else{
            while(!ope.empty() && (precedence(ope.top()) >= precedence(infix[i]))){
                postfix += ope.top();
                ope.pop();
            }
            ope.push(infix[i]);
        }
    }
    while(!ope.empty() ){
                postfix += ope.top();
                ope.pop();
    }
    return postfix;
}


int main() {
    string str = "(A+2)*(3^B)";
    cout << infixToPostfix(str) << "\n";
    
    
    return 0;
}
