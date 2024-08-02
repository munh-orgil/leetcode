#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        n *= 2;
        int sum = 0;
        int ret = 1e9;
        for (int i = 0; i < n; i++) {
            if (i < cnt) {
                sum += nums[i];
                continue;
            }
            ret = min(ret, cnt - sum);
            sum = sum - nums[i - cnt] + nums[i];
        }
        ret = min(ret, cnt - sum);
        return ret;
    }
};