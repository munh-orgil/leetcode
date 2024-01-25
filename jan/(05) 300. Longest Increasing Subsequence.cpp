#include<bits/stdc++.h>

using namespace std;

#define debug(n) cout << #n << " = " << n << endl;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        const int INFI = 0x3f3f3f3f;
        vector<int> dp(n + 1, INFI);
        dp[0] = -INFI;
        for (int i = 0; i < n; i++) {
            int x = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if (dp[x - 1] < nums[i] && nums[i] < dp[x]) {
                dp[x] = nums[i];
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (dp[i] != INFI) {
                ans = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution{};
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = sol.lengthOfLIS(a);
    cout << res << endl;
}
