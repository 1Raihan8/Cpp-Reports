#include <bits/stdc++.h>
using namespace std;

int SumOfNthElements(int n);

int main(){
    int num, sum;
    cout << "Enter the number of wanted sum: ";
    cin >> num;

    sum = SumOfNthElements(num);
    cout << "The sum is: " << sum << endl;
    return 0;
}

int SumOfNthElements(int n){
    if(n == 0){
        return 0;
    }
    int sum = n + SumOfNthElements(n-1);
    return sum;
}