#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum >= n) {
                break;
            }
            if (nums[i] <= sum + 1) {
                sum += nums[i];
                continue;
            }
            ret++;
            sum += sum + 1;
            i--;
        }
        while (sum < n) {
            sum += sum + 1;
            ret++;
        }
        return ret;
    }
};