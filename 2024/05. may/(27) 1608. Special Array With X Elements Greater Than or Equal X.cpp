#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = n;
        int pt = 0;
        for (int i = 0; i <= nums[n - 1]; i++) {
            while (i > nums[pt]) {
                cnt--;
                pt++;
            }
            if (i == cnt) {
                return cnt;
            }
        }
        return -1;
    }
};