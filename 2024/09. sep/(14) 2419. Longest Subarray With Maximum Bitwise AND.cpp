#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
        }
        int cnt = 0, ret = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) {
                cnt++;
            }
            else {
                ret = max(ret, cnt);
                cnt = 0;
            }
        }
        ret = max(ret, cnt);
        return ret;
    }
};