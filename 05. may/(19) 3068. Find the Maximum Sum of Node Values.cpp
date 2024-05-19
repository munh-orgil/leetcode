#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    long long maximumValueSum(vector<int>& nums, int k, const vector<vector<int>>& edges) {
        int n = nums.size();
        int dif, cnt = 0, mn = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            dif = (nums[i] ^ k) - nums[i];
            mn = min(mn, abs(dif));
            if (dif > 0) {
                cnt++;
                sum += (nums[i] ^ k);
            }
            else {
                sum += nums[i];
            }
        }
        if (cnt & 1) {
            sum -= mn;
        }
        return sum;
    }
};