#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, max = 100;
    cout << "Enter the size for first Array: ";
    cin >> n;
    int A[max];
    
    for(int i=0; i<n; i++){
        cout << "Enter element: " << (i+1) << ": ";
        cin >> A[i];
    }

    cout << "Enter the size for second Array: ";
    cin >> m;
    int B[max];
    
    for(int i=0; i<m; i++){
        cout << "Enter element: " << (i+1) << ": ";
        cin >> B[i];
    }

    if(n + m > max){
        cout << "Array overflows!" << endl;
        return 0;
    }

    if(n == 0){
        for(int i = 0; i < m; i++){
            A[i] = B[i];
        }
        n = m;
    }
    else{
        for(int i = 0; i < m; i++){
            A[n+i] = B[i];
        }
        n = n + m;
    }
    
    cout << "Merged Array: ";
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}