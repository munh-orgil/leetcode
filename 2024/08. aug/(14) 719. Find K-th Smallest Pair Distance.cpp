#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n, 0), d(n);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            d[i] = nums[i + 1] - nums[i];
            pre[i + 1] = pre[i] + d[i];
        }
        int l = 0, r = 1e6;
        int m;
        int ret = r;
        while (l <= r) {
            m = (l + r) / 2;
            int cnt = 0;
            for (int i = 0; i < n - 1;i++) {
                int j = min(int(upper_bound(pre.begin(), pre.end(), pre[i] + m) - pre.begin()), n - 1);
                while (pre[j] - pre[i] > m) {
                    j--;
                }
                cnt += j - i;
            }
            if (cnt >= k) {
                r = m - 1;
                ret = min(ret, m);
            } else {
                l = m + 1;
            }
        }
        return ret;
    }
};