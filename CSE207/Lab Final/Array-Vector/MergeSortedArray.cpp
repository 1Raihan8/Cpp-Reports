#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void mergeSortedArray(vector<int> nums1, int m, vector<int> nums2, int n){
        int t = n + m;
        int k = 0;
        for(int i = m; i < t; i++){
            nums1[i] = nums2[k];
            k++;
        }

        sort(nums1.begin(), nums1.end());
        for(int i = 0; i < t; i++){
            cout << nums1[i] << " ";
        }     
        cout << endl;
    }

};

int main(){
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);

        vector<int> v2;
        v2.push_back(2);
        v2.push_back(5);
        v2.push_back(6);

        Solution sol;

        sol.mergeSortedArray(v1, 3, v2, 3);

        return 0;
    }