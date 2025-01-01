#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    Solution() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        int idx;
        for (int i = 0; i < n; i++) {
            idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                ret.push_back(idx + 1);
            }
            else {
                nums[idx] = -nums[idx];
            }
        }
        return ret;
    }
};