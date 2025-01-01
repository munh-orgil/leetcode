#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, bool> mp;
        int n = nums.size();
        int s = nums[0] % k;
        mp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (mp.find((s + nums[i]) % k) != mp.end()) {
                return 1;
            }
            mp[s] = true;
            s = (s + nums[i]) % k;
        }
        return false;
    }
};