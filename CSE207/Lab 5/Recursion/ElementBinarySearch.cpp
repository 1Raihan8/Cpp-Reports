#include <bits/stdc++.h>
using namespace std;

int searchBinaryElement(int arr[], int t, int l, int r);

int main(){
    int arr[10];
    int target, n, l, r;

    cout << "Enter the size of array: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter element " << (i+1) << ": ";
        cin >> arr[i];
    }

    cout << "Enter required element: ";
    cin >> target;

    l = 0, r = n-1;
    int res = searchBinaryElement(arr, target, l, r);
    if(res == 1){
        cout << "Element is found" << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
}

int searchBinaryElement(int arr[], int t, int l, int r){
    int c = 0, mid;

    if(l <= r){
        mid = (l + r) / 2;

        if(t == arr[mid]){
            c = 1;
        }
        else if(t < arr[mid]){
            return searchBinaryElement(arr, t, l, mid-1);
        }
        else{
            return searchBinaryElement(arr, t, mid+1, r);
        }
    }
    
    return c;
}