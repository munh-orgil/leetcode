#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int rangeSum(const vector<int>& nums, int n, int left, int right) {
        vector<int> sums, pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                sums.push_back(pre[j + 1] - pre[i]);
            }
        }
        sort(sums.begin(), sums.end());
        int ret = 0;
        const int mod = 1e9 + 7;
        for (int i = left - 1; i < right; i++) {
            ret = (ret + sums[i]) % mod;
        }
        return ret;
    }
};