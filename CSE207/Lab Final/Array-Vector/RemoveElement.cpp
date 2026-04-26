#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int> nums, int val){
        int n = nums.size();
        int k = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }

    void print(vector<int> nums, int val){
        int n = nums.size();
        int k = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        for(int i = 0; i < k; i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main(){
        vector<int> v;
        v.push_back(3);
        v.push_back(2);
        v.push_back(2);
        v.push_back(3);

        Solution sol;

        int n = sol.removeDuplicates(v, 3);
        cout << n << endl;
        sol.print(v, 3);

        return 0;
    }