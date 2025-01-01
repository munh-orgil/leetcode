#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int subsetXORSum(const vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int N = 1 << n;
        int sum = 0;
        int x;
        for (int i = 0; i < N; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    sum ^= nums[j];
                }
            }
            ans += sum;
        }
        return ans;
    }
};