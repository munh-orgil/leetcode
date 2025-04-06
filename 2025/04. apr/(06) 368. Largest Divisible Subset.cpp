#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), child(n), ans;
        int mx = 0, idx;
        for (int i = 0; i < n; i++) {
            child[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    child[i] = j;
                }
            }
            if (dp[i] > mx) {
                mx = dp[i];
                idx = i;
            }
        }
        ans.push_back(nums[idx]);
        while (idx != child[idx]) {
            idx = child[idx];
            ans.push_back(nums[idx]);
        }

        return ans;
    }
};