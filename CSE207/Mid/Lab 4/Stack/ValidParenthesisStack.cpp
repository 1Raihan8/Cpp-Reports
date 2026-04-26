#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s);

int main(){
    string expression;
    cout << "Enter a string with parenthesis: ";
    cin >> expression;

    if(isValidParenthesis(expression)){
        cout << "The parenthesis is valid" << endl;
    }
    else{
        cout << "The parenthesis is not valid" << endl;
    }

    return 0;
}

bool isValidParenthesis(string s){
    stack<char> stk;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '{' || ch == '['){
            stk.push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(stk.empty()){
                return false;
            }
            char top = stk.top();
            stk.pop();

            if((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')){
                return false;
            }
        }
    }

    if(stk.empty()){
        return true;
    }
    else{
        return false;
    }
}