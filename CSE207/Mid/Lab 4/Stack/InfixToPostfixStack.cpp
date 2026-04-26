#include <bits/stdc++.h>
using namespace std;

void infixToPostfix(string s);
int main(){
    string expression;
    cout << "Enter the string expression: ";
    cin >> expression;

    infixToPostfix(expression);
    return 0;
}

void infixToPostfix(string s){
    stack<char> stk;
    string output;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        if((ch == '(') || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')){
            stk.push(ch);
        }
        else if((ch >= 'A' && ch <='Z') || (ch >= 'a' && ch <= 'z')){
            output = output + ch;
        }
        else if((ch == ')')){
            char top = stk.top();
            output = output + top;
            stk.pop();
            stk.pop();
        }
    }
    cout << "Postfix: " << output << endl;
} 