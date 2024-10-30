#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n), dp2(n), arr, pre(n + 1, 1e9), suf(n + 1, 1e9);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = min(pre[i], nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
            dp1[i] = idx + 1;
            if (idx == arr.size()) {
                arr.push_back(nums[i]);
                continue;
            }
            arr[idx] = nums[i];
        }
        arr.clear();
        for (int i = n - 1; i >= 0; i--) {
            int idx = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
            dp2[i] = idx + 1;
            if (idx == arr.size()) {
                arr.push_back(nums[i]);
                continue;
            }
            arr[idx] = nums[i];
        }

        int mx = 0;
        for (int i = 1; i < n - 1; i++) {
            if (pre[i] < nums[i] && suf[i] < nums[i]) {
                mx = max(mx, dp1[i] + dp2[i] - 1);
            }
        }
        int ret = n - mx;
        return ret;
    }
};