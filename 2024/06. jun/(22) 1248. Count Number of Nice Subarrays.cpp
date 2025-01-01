#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> odds;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2) {
                odds.push_back(i);
            }
        }
        int m = odds.size();
        if (m < k) {
            return 0;
        }
        int l, r, ret = 0;
        for (int i = k; i < m; i++) {
            if (i == k) {
                l = odds[i - k] + 1;
            } else {
                l = odds[i - k] - odds[i - k - 1];
            }
            if (i == m - 1) {
                r = n - odds[i];
            } else {
                r = odds[i + 1] - odds[i];
            }
            ret += r * l;
        }
        return ret;
    }
};