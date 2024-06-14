#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                ret += (nums[i - 1] - nums[i] + 1);
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ret;
    }
};