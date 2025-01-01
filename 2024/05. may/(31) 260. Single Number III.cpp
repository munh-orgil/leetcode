#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long x = 0;
        for (int num : nums) {
            x ^= num;
        }
        int last = x & (-x);
        vector<int> ret(2, 0);
        for (int num : nums) {
            if (num & last) {
                ret[0] ^= num;
            }
            else {
                ret[1] ^= num;
            }
        }
        return ret;
    }
};