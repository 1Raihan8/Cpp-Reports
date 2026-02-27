#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n);

int main(){
    int num;
    cout << "Enter the number: ";
    cin >> num;

    int result = fibonacci(num);
    cout << "The N-th fibonacci is: " << result << endl;
    return 0;
}

int fibonacci(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }

    int r = fibonacci(n - 1) + fibonacci(n - 2);
    return r;
}