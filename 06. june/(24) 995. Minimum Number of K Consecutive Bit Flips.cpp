#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flip = 0;
        int ret = 0;
        vector<int> end(n + k, 0);
        for (int i = 0; i < n; i++) {
            flip ^= end[i];
            nums[i] ^= flip;
            if (!nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flip ^= 1;
                ret++;
                end[i + k] ^= 1;
            }
        }
        return ret;
    }
};