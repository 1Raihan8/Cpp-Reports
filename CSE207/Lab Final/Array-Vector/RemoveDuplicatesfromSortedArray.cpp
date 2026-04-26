#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int removeDuplicatesFromSortedArray(vector<int> nums){
        set<int> s;
        for(int x : nums){
            s.insert(x);
        }

        nums.clear();
        nums.assign(s.begin(), s.end());
        int k = s.size();
        return k;
    }

    void print(vector<int> nums){
        set<int> s;
        for(int x : nums){
            s.insert(x);
        }

        nums.clear();
        nums.assign(s.begin(), s.end());
        for(int x : nums){
            cout << x << " ";
        }
        cout << endl;
    }
};

int main(){
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        v.push_back(2);

        Solution sol;

        int n = sol.removeDuplicatesFromSortedArray(v);
        cout << n << endl;
        sol.print(v);

        return 0;
    }