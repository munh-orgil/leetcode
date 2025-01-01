#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    Solution() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
        }
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) {
                pos.push_back(i);
            }
        }
        int m = pos.size();
        pos.push_back(n - 1);
        int l, r, ans = 0;
        for (int i = 0; i <= m - k; i++) {
            ans += (pos[i] + 1) * (pos[i + k] - pos[i + k - 1] + 1);
        }
        return ans;
    }
};