#include <bits/stdc++.h>
using namespace std;

void convertToBinary(int n);

int main(){
    int num;
    cout << "Enter the number: ";
    cin >> num;
    
    cout << "The binary is: ";
    convertToBinary(num);
    return 0;
}

void convertToBinary(int n){
    if(n == 0){
        return;
    }

    convertToBinary(n/2);
    cout << n%2;
}