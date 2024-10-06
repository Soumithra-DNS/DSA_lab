#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c) {
    return isdigit(c);
}

int applyOperation(int firstValue, int secondValue, char ope) {
    switch (ope) {
        case '+': return firstValue + secondValue;
        case '-': return firstValue - secondValue;
        case '*': return firstValue * secondValue;
        case '/': return firstValue / secondValue;
        case '^': return pow(firstValue, secondValue); // Using pow for exponentiation
    }
    return 0;
}

int precedence(char ope) {
    if (ope == '+' || ope == '-') return 1;
    if (ope == '*' || ope == '/') return 2;
    if (ope == '^') return 3; // Higher precedence for exponentiation
    return 0;
}

int infixEva(string str) {
    stack<int> values;
    stack<char> ope;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            continue;
        } else if (str[i] == '(') {
            ope.push(str[i]);
        } else if (isOperand(str[i])) {
            int val = 0;
            while (i < str.size() && isOperand(str[i])) {
                val = val * 10 + (str[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        } else if (str[i] == ')') {
            while (ope.top() != '(') {
                int secondValue = values.top();
                values.pop();
                int firstValue = values.top();
                values.pop();
                char ch = ope.top();
                ope.pop();
                values.push(applyOperation(firstValue, secondValue, ch));
            }
            ope.pop(); // Remove '('
        } else {
            while (!ope.empty() && precedence(ope.top()) >= precedence(str[i])) {
                int secondValue = values.top();
                values.pop();
                int firstValue = values.top();
                values.pop();
                char ch = ope.top();
                ope.pop();
                values.push(applyOperation(firstValue, secondValue, ch));
            }
            ope.push(str[i]);
        }
    }

    while (!ope.empty()) {
        int secondValue = values.top();
        values.pop();
        int firstValue = values.top();
        values.pop();
        char ch = ope.top();
        ope.pop();
        values.push(applyOperation(firstValue, secondValue, ch));
    }

    return values.top();
}

void checkString(string &str) {
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            int value;
            cout << "Enter the value of " << str[i] << ": ";
            cin >> value;

            // Replace the variable with the corresponding value
            str.replace(i, 1, to_string(value));
        }
    }
}

int main() {
    string str = "(A+2+1)*(3-B)";
    
    // Ask for variable values
    checkString(str);

    cout << "Modified expression: " << str << "\n";
    
    // Evaluate the infix expression
    cout << "Result: " << infixEva(str) << "\n";

    return 0;
}
