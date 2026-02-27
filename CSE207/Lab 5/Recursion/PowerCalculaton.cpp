#include <bits/stdc++.h>
using namespace std;

int powerCalculation(int n, int p);

int main(){
    int num, pow;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the power: ";
    cin >> pow;

    int result = powerCalculation(num, pow);
    cout << "The result is: " << result << endl;
    return 0;
}

int powerCalculation(int n, int p){
    if(p == 0){
        return 1;
    }
    int r = n * powerCalculation(n, p-1);
    return r;
}