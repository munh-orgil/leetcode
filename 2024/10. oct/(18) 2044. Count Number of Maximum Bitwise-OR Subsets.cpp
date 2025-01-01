#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int b = 1 << n;
        int x, y = 0;
        for (int i = 0; i < n; i++) {
            y |= nums[i];
        }
        int ret = 0;
        for (int i = 0; i < b; i++) {
            x = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    x |= nums[j];
                }
            }
            if (x == y) {
                ret++;
            }
        }
        return ret;
    }
};