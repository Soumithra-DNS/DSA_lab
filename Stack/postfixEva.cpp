//Prefix Evaluation
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c){
    return isdigit(c);
}

double postfixEva(string str){
    stack<double> st;
    for(int i = 0; i < str.size(); i++){
        if(isOperand(str[i])){
            st.push(str[i] - '0');
        }else{
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            
            switch(str[i]){
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
                case '/':
                    st.push(operand1 / operand2);
                    break;
                case '^':
                    st.push(pow(operand1, operand2));
                    break;
            }
            
        }
        
    }
    return st.top();
}
void checkString(string &str){
    char ch;
    for(int i = 0; i < str.size(); i++){
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            cout << "Enter the value of " << str[i] <<": ";
            cin >> ch;
            str[i] = ch;
        }
    }
}
int main(){
    string str;
    cin >> str;
    
    checkString(str);
    cout << str << "\n";
    
    cout << postfixEva(str) << "\n";
    
}
