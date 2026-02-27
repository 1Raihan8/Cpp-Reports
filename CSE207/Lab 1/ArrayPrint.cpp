#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;

    cout << "Enter the size of the Array: ";
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cout << "Enter element " << (i+1) << ": ";
        cin >> arr[i];
    }

    cout << "The Array: ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}