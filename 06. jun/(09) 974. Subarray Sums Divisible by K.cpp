#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            pre[i + 1] = ((pre[i] + nums[i]) % k + k) % k;
        }
        for (int i = 0; i <= n; i++) {
            cnt[pre[i]]++;
        }
        int ret = 0;
        for (auto [key, v] : cnt) {
            ret += (v * (v - 1)) / 2;
        }
        return ret;
    }
};