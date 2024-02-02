#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define ll long long

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<ll, int>> dp(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ll diff = (ll)nums[i] - nums[j];
                int x = dp[j][diff];
                dp[i][diff] += x + 1;
                ans += x;
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
    int res = sol.numberOfArithmeticSlices(a);
    cout << res << endl;
}