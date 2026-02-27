#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cout << "Enter element " << (i+1) << ": ";
        cin >> arr[i];
    }

    int num;
    cout << "Enter the element: ";
    cin >> num;

    for(int i=0; i<n; i++){
        if(num==arr[i]){
            cout << "Element found at position: " << (i+1);
            return 0;
        }
    }
    
    cout << "Element not Found";
    return 0;
}