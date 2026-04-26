#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int searchInsertPosition(vector<int> nums, int target){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] >= target){
                return i;
            }
        }

        return n;
    }

};

int main(){
        vector<int> v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(5);
        v.push_back(6);

        Solution sol;

        int n = sol.searchInsertPosition(v, 5);
        cout << n << endl;

        return 0;
    }