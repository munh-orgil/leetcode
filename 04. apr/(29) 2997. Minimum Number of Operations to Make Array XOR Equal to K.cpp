#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int x = k;
        for (int i = 0; i < n; i++) {
            x ^= nums[i];
        }
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            int y = 1 << i;
            if (x & y) {
                ret++;
            }
        }
        return ret;
    }
};