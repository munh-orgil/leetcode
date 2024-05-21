#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int N = 1 << n;
        vector<vector<int>> ret;
        for (int i = 0; i < N; i++) {
            vector<int> sub;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sub.push_back(nums[j]);
                }
            }
            ret.push_back(sub);
        }
        return ret;
    }
};