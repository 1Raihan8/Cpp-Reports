#include <bits/stdc++.h>
using namespace std;

int factorialCalculation(int n);

int main(){
    int num;
    cout << "Enter the number: ";
    cin >> num;

    int result = factorialCalculation(num);
    cout << "The result is: " << result << endl;
    return 0;
}

int factorialCalculation(int n){
    if(n == 0){
        return 1;
    }

    int r = n * factorialCalculation(n-1);
    return r;
}