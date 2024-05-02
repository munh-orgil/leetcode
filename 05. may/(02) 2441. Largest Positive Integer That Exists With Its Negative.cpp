#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int pt = 0;
        for (int i = n - 1; i > pt && nums[i] > 0; i--) {
            while (pt < n && abs(nums[pt]) > nums[i]) {
                pt++;
            }
            if (pt > n - 1 || nums[pt] > 0) {
                return -1;
            }
            if (abs(nums[pt]) == nums[i]) {
                return nums[i];
            }
        }
        return -1;
    }
};